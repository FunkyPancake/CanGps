//
// Created by PC on 23.05.2021.
//

#include "EmuCan.h"

void EmuCan::SendFrames()
{
    {
        ICan::Payload buf{};
        buf.dw[0] = SwapBytes<int32_t>(ScaleCoord(_gps.Latitude_deg));
        buf.dw[1] = SwapBytes<int32_t>(ScaleCoord(_gps.Longitude_deg));
    
        _can->Send(_baseId, buf, 8);
    }
    {
        ICan::Payload buf{};
        buf.w[0] = SwapBytes<int16_t>((int16_t) (_gps.Speed_mps * 100.0f));
        buf.w[1] = SwapBytes<int16_t>((int16_t) (_gps.Altitude_m));
        buf.b[4] = _gps.Noise;
        buf.b[5] = _gps.SateliteNumber;
        buf.b[6] = frameCounter;
        buf.b[7] = _gps.Status;
        _can->Send(_baseId + 1, buf, 8);
    }
    {
        ICan::Payload buf{};
        buf.w[0] = (ScaleHeading(_gps.Course_deg));
        buf.w[1] = (ScaleHeading(_gps.Course_deg));
//        buf.w[2] = static_cast<uint16_t>(ScaleImu(imu.Xyaw));
//        buf.w[3] = static_cast<uint16_t>(ScaleImu(imu.Yyaw));
        _can->Send(_baseId + 2, buf, 8);
    }
    {
        ICan::Payload buf{};
//        buf.w[0] = static_cast<uint16_t>(ScaleImu(imu.Zyaw));
//        buf.w[1] = static_cast<uint16_t>(ScaleImu(imu.Xacc));
//        buf.w[2] = static_cast<uint16_t>(ScaleImu(imu.Yacc));
//        buf.w[3] = static_cast<uint16_t>(ScaleImu(imu.Zacc));
        _can->Send(_baseId + 3, buf, 8);
    }
    frameCounter++;
}

uint16_t EmuCan::ScaleHeading(float heading)
{
    return (uint16_t) heading;
}

int32_t EmuCan::ScaleCoord(float coord)
{
    return ((int32_t) (coord * 1e7f));
}

EmuCan::EmuCan(IGps &gps, ICan *can, uint32_t baseId = 0x400) : _gps(gps)
{
    frameCounter = 0;
    _can = can;
    _baseId = baseId;
}