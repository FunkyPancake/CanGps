//
// Created by PC on 23.05.2021.
//

#include "App.h"
#include "FreeRTOS.h"
#include "peripherals.h"

#include "Gps.h"
#include "Imu.h"
#include "GpsUbx.h"
#include "EmuCan.h"
#include "flexcan.h"

const UBaseType_t app_task_PRIORITY =  (configMAX_PRIORITIES - 1);

[[noreturn]] static void app_task(void *pvParameters);

[[noreturn]] static void app_task(void *pvParameters)
{
    TickType_t xLastWakeTime;
    const TickType_t xFrequency = 2;
    xLastWakeTime = xTaskGetTickCount();
    FlexCan can{};
    GpsUbx ubx{};
    Imu imu{};
    EmuCan emuCan(ubx,imu,&can,0x400);

    for(;;)
    {

        emuCan.SendFrames();
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
    }
}
void App()
{
    if(xTaskCreate(app_task, "app_task", configMINIMAL_STACK_SIZE + 1000, NULL, app_task_PRIORITY, NULL) != pdPASS)
    {
        while(1)
            ;
    }
}