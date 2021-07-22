//
// Created by PC on 22.05.2021.
//

#include <algorithm>
#include "GpsUbx.h"
#include "UbxMessage.h"
#include <array>

uint32_t GpsUbx::ParseU32(uint8_t *rawData)
{
    return *(uint32_t *) rawData;
}

bool GpsUbx::ParseMessage(std::vector<uint8_t> message)
{
    UbxMessage msg = UbxMessage();
    if (msg.Deserialize(message))
    {
        if (msg.MsgClass == NAV && msg.MsgSubclass == NAV_PVT)
        {
            Status = msg.Payload[20];
            SateliteNumber = msg.Payload[23];
            Longitude_deg = (float)ParseU32(msg.Payload.data() + 24) / 1e7f;//*(float*)(msg.Payload.data()+24);
            Latitude_deg = (float)ParseU32(msg.Payload.data() + 28) / 1e7f;
            Altitude_m = (float)ParseU32(msg.Payload.data() + 36)/1e3f;
            Speed_mps = (float)ParseU32(msg.Payload.data() + 60)/1e3f;
            Course_deg = (float)ParseU32(msg.Payload.data()+64)/1e5f;
        }
    }
    return false;
}

GpsUbx::GpsUbx()
{
}

