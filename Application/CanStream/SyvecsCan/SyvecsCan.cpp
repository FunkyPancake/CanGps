//
// Created by PC on 23.05.2021.
//

#include "SyvecsCan.h"

void SyvecsCan::SendFrames()
{
    {
        ICan::Payload buf{};
        buf.dw[0] = SwapBytes<uint32_t>(ScaleCoord(_gps.Latitude_deg));
        buf.dw[1] = SwapBytes<uint32_t>(ScaleCoord(_gps.Longitude_deg));
        _can->Send(_baseId, buf, 8);
    }
    {
        ICan::Payload buf{};
        buf.w[0] = SwapBytes<int16_t>(ScaleSpeed(_gps.Speed_mps));
        buf.w[1] = SwapBytes<int16_t>((int16_t) _gps.Altitude_m);
        _can->Send(_baseId + 1, buf, 8);
    }
}

int32_t SyvecsCan::ScaleCoord(float coord)
{
    return (int32_t) (coord * 1e7f / 60.0f);
}

int16_t SyvecsCan::ScaleSpeed(float speed)
{
    return (int16_t) (speed * 36.0f);
}

SyvecsCan::SyvecsCan(IGps &gps, ICan *can, uint32_t baseId) : _gps(gps)
{
    _can = can;
    _baseId = baseId;
}
