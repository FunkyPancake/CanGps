//
// Created by PC on 23.05.2021.
//

#include <Imu.h>
#include "EmuCan.h"

void EmuCan::SendFrames() {
    {
        ICan::Payload buf{};
        buf.dw[0] = static_cast<uint32_t>(ScaleCoord(gps.Latitude));
        buf.dw[1] = static_cast<uint32_t>(ScaleCoord(gps.Longitude));

        can->Send(baseId, buf, 8);
    }
    {
        ICan::Payload buf{};
        buf.w[0] = static_cast<uint16_t>(gps.Speed),
        buf.w[1] = static_cast<uint16_t>(gps.Altitude),
        buf.b[4] = gps.Noise,
        buf.b[5] = gps.SateliteNumber,
        buf.b[6] = frameCounter,
        buf.b[7] = gps.Status,
                can->Send(baseId + 1, buf, 8);
    }
    {
        ICan::Payload buf{};
        buf.w[0] = (ScaleHeading(gps.Course)),
        buf.w[1] = (ScaleHeading(gps.Course)),
        buf.w[2] = static_cast<uint16_t>(ScaleImu(imu.Xyaw)),
        buf.w[3] = static_cast<uint16_t>(ScaleImu(imu.Yyaw)),
                can->Send(baseId + 2, buf, 8);
    }
    {
        ICan::Payload buf{};
        buf.w[0] = static_cast<uint16_t>(ScaleImu(imu.Zyaw)),
        buf.w[1] = static_cast<uint16_t>(ScaleImu(imu.Xacc)),
        buf.w[2] = static_cast<uint16_t>(ScaleImu(imu.Yacc)),
        buf.w[3] = static_cast<uint16_t>(ScaleImu(imu.Zacc)),
                can->Send(baseId + 3, buf, 8);
    }
    frameCounter++;
}

uint16_t EmuCan::ScaleHeading(float heading) {
    return 0;
}

int32_t EmuCan::ScaleCoord(float coord) {
    return coord / 10e7;
}

int16_t EmuCan::ScaleImu(float data) {
    return data / 100;
}

EmuCan::EmuCan(Gps &gps, Imu &imu, ICan *can, uint32_t baseId = 0x400) : gps(gps), imu(imu) {
    frameCounter = 0;
    this->can = can;
    this->baseId = baseId;
}
