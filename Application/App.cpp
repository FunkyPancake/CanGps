//
// Created by PC on 23.05.2021.
//

#include "App.h"
#include "FreeRTOS.h"
#include "peripherals.h"
#include <LpSpi.h>
#include <Tle9461.h>

#include "LpUart.h"
#include "EmuCan.h"
#include "FlexCan.h"
#include "Imu.h"
#include "NeoM9N.h"

const UBaseType_t app_task_PRIORITY = (configMAX_PRIORITIES - 1);

[[noreturn]] static void app_task(void *pvParameters);

[[noreturn]] static void app_task(void *pvParameters)
{
    (void)pvParameters;
    TickType_t xLastWakeTime;
    const TickType_t xFrequency = 40;
    xLastWakeTime = xTaskGetTickCount();
    LpSpiRtos sbcSpi{&LPSPI0_handle};
    LpUart uartGps{&LPUART0_rtos_handle,LPUART0_rtos_config.srcclk};
    Tle9461 sbc{&sbcSpi};
    FlexCan can{16};
    Imu imu{};
    NeoM9N gps{&uartGps};
    EmuCan emuCan(gps, imu, &can, 0x400);
    sbc.Init();
//    sbc.ConfigWatchdog();
    vTaskDelayUntil(&xLastWakeTime, 1250);
    gps.Config();
    imu.Config();
    for (;;)
    {
        gps.GetData();
        imu.GetData();
        emuCan.SendFrames();
        sbc.RefreshWatchdog();
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
    }
}

void App()
{
    if (xTaskCreate(app_task, "app_task", configMINIMAL_STACK_SIZE + 1000, nullptr, app_task_PRIORITY, nullptr)
        != pdPASS)
    {
        while (true)
            ;
    }
}