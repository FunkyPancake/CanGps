//
// Created by PC on 24.05.2021.
//

#include <UbxTp.h>
#include "NeoM9N.h"

void NeoM9N::Config()
{
//    ValSet<uint32_t>(CfgUart1Baudrate,115200);
    _com->SetBaudrate(115200);
    ValSet<bool>(CfgUart1OutProtNmea, false);
    ValSet<bool>(CfgUart1OutProtUbx, true);
    ValSet<uint8_t>(CfgMsgoutUbxNavPvtUart1, 1);
    ValSet<uint16_t>(CfgRateMeas, 40);
}

bool NeoM9N::GetData()
{
    auto msg = UbxTp::Deserialize(_com->ReadBytes(100));
    if (msg.MsgClass == NAV && msg.MsgSubclass == NAV_PVT)
    {
        
        Status = msg.Payload[20];
        if(Status >1)
        {
            SateliteNumber = msg.Payload[23];
            Longitude_deg = (float) GetU32Value(msg.Payload.data() + 24) / 1e7f;
            Latitude_deg = (float) GetU32Value(msg.Payload.data() + 28) / 1e7f;
            Altitude_m = (float) GetU32Value(msg.Payload.data() + 36) / 1e3f;
            Speed_mps = (float) GetU32Value(msg.Payload.data() + 60) / 1e3f;
            Course_deg = (float) GetU32Value(msg.Payload.data() + 64) / 1e5f;
        }
    }
    return true;
}

uint32_t NeoM9N::GetU32Value(const uint8_t *rawData)
{
    return *(uint32_t *) rawData;
}

NeoM9N::NeoM9N(ICom *com) : GpsUbx(com), Gps()
{
}
