//
// Created by PC on 23.05.2021.
//

#include "App.h"
#include "FreeRTOS.h"
#include "peripherals.h"

#include "Imu.h"
#include "GpsUbx.h"
#include "EmuCan.h"
#include "FlexCan.h"
#include "NeoM9N.h"

const UBaseType_t app_task_PRIORITY = (configMAX_PRIORITIES - 1);

[[noreturn]] static void app_task(void *pvParameters);

[[noreturn]] static void app_task(void *pvParameters)
{
    TickType_t xLastWakeTime;
    const TickType_t xFrequency = 2;
    xLastWakeTime = xTaskGetTickCount();
    FlexCan can{};
    GpsUbx ubx{};
    Imu imu{};
    NeoM9N gpsDevice;
    EmuCan emuCan(ubx, imu, &can, 0x400);
    gpsDevice.Config();
    
    for (;;)
    {
        auto data = gpsDevice.GetData();
        ubx.ParseMessage(data);
        emuCan.SendFrames();
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
    }
}

void App()
{
    if (xTaskCreate(app_task, "app_task", configMINIMAL_STACK_SIZE + 1000, nullptr, app_task_PRIORITY, nullptr)
        != pdPASS)
    {
        while (1);
    }
}