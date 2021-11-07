//
// Created by PC on 23.05.2021.
//

#pragma once

#include <Interfaces/ICanStream.h>
#include <IGps.h>

class EmuCan : public ICanStream
{
private:
    IGps &_gps;
    uint8_t frameCounter;
    static uint16_t ScaleHeading(float heading);
    static int32_t ScaleCoord(float coord);
public:
    EmuCan(IGps &gps, ICan *can, uint32_t baseId);
    void SendFrames() override;
};