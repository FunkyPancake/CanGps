//
// Created by PC on 24.07.2021.
//

#ifndef CANGPS_APPLICATION_SYVECSCAN_H
#define CANGPS_APPLICATION_SYVECSCAN_H

#include <cstdint>
#include <Gps.h>
#include <ICan.h>
#include <algorithm>

class SyvecsCan
{
private:
    int _baseId;
    ICan *_can;
    Gps &_gps;
    
    static int32_t ScaleCoord(float coord);
    static int16_t ScaleSpeed(float speed);
    template<typename T> T SwapBytes(T data);

public:
    SyvecsCan(Gps &gps, ICan *can, uint32_t baseId = 0x680);
    void SendFrames();
    
};

#endif //CANGPS_APPLICATION_SYVECSCAN_H
