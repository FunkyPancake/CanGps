//
// Created by PC on 23.05.2021.
//

#pragma once


#include <cstdint>
#include "Gps.h"
#include "ICan.h"
#include "Imu.h"

class EmuCan
{
private:
    Gps &gps;
    Imu &imu;
    ICan *can;
    uint8_t frameCounter;
    uint32_t baseId;
    static int16_t ScaleImu(float data);
    static uint16_t ScaleHeading(float heading);
    static uint32_t ScaleCoord(float coord);
public:
    EmuCan(Gps &gps, Imu &imu, ICan *can, uint32_t baseId);
    void SendFrames();
};