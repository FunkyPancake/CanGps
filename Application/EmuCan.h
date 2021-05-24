//
// Created by PC on 23.05.2021.
//

#ifndef CANGPS_EMUCAN_H
#define CANGPS_EMUCAN_H

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
    int16_t ScaleImu(float data);
    uint16_t ScaleHeading(float heading);
    int32_t ScaleCoord(float coord);
public:
    EmuCan(Gps &gps, Imu &imu, ICan *can, uint32_t baseId);
    void SendFrames();
};

#endif //CANGPS_EMUCAN_H
