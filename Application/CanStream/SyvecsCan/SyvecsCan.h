//
// Created by PC on 24.07.2021.
//

#pragma once

#include <Interfaces/ICanStream.h>
#include <IGps.h>

class SyvecsCan : public ICanStream
{
private:
    IGps &_gps;
    static int32_t ScaleCoord(float coord);
    static int16_t ScaleSpeed(float speed);
public:
    SyvecsCan(IGps &gps, ICan *can, uint32_t baseId = 0x680);
    void SendFrames() override;
};