//
// Created by PC on 23.05.2021.
//

#include <Imu.h>
#include <array>
#include "EmuCan.h"
#include <algorithm>

void EmuCan::SendFrames()
{
    {
        ICan::Payload buf{};
        buf.dw[0] = SwapBytes<int32_t>(ScaleCoord(gps.Latitude_deg));
        buf.dw[1] = SwapBytes<int32_t>(ScaleCoord(gps.Longitude_deg));
        
        can->Send(baseId, buf, 8);
    }
    {
        ICan::Payload buf{};
        buf.w[0] = SwapBytes<int16_t>((int16_t) (gps.Speed_mps * 100.0f));
        buf.w[1] = SwapBytes<int16_t>((int16_t) (gps.Altitude_m));
        buf.b[4] = gps.Noise;
        buf.b[5] = gps.SateliteNumber;
        buf.b[6] = frameCounter;
        buf.b[7] = gps.Status;
        can->Send(baseId + 1, buf, 8);
    }
    {
        ICan::Payload buf{};
        buf.w[0] = (ScaleHeading(gps.Course_deg));
        buf.w[1] = (ScaleHeading(gps.Course_deg));
        buf.w[2] = static_cast<uint16_t>(ScaleImu(imu.Xyaw));
        buf.w[3] = static_cast<uint16_t>(ScaleImu(imu.Yyaw));
        can->Send(baseId + 2, buf, 8);
    }
    {
        ICan::Payload buf{};
        buf.w[0] = static_cast<uint16_t>(ScaleImu(imu.Zyaw));
        buf.w[1] = static_cast<uint16_t>(ScaleImu(imu.Xacc));
        buf.w[2] = static_cast<uint16_t>(ScaleImu(imu.Yacc));
        buf.w[3] = static_cast<uint16_t>(ScaleImu(imu.Zacc));
        can->Send(baseId + 3, buf, 8);
    }
    frameCounter++;
}

uint16_t EmuCan::ScaleHeading(float heading)
{
    return (uint16_t) heading;
}

uint32_t EmuCan::ScaleCoord(float coord)
{
    return ((int32_t) (coord * 1e7f));
}

int16_t EmuCan::ScaleImu(float data)
{
    return (int16_t) (data / 100.0f);
}

EmuCan::EmuCan(Gps &gps, Imu &imu, ICan *can, uint32_t baseId = 0x400) : gps(gps), imu(imu)
{
    frameCounter = 0;
    this->can = can;
    this->baseId = baseId;
}

template<typename T> T EmuCan::SwapBytes(T data)
{
    {
        std::array<uint8_t, sizeof(T)> tmp{};
        *(T *) tmp.data() = data;
        std::reverse(tmp.begin(), tmp.end());
        return *(T *) tmp.data();
    }
}
