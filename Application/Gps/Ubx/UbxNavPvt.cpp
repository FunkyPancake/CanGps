//
// Created by PC on 25.10.2021.
//

#include "UbxNavPvt.h"
#include "UbxTp.h"

uint32_t UbxNavPvt::GetU32Value(const uint8_t *rawData)
{
    return *(uint32_t *) rawData;
}

UbxNavPvt::UbxNavPvt(ICom *pCom)
{
    _com = pCom;
}

bool UbxNavPvt::GetFrame()
{
    auto msg = UbxTp::Deserialize(_com->ReadBytes(100));
    if (msg.MsgClass == MsgClass && msg.MsgSubclass == MsgSubclass)
    {
        Status = msg.Payload[20];
        if (Status > 1)
        {
            SateliteNumber = msg.Payload[23];
            Longitude_deg = (float) GetU32Value(msg.Payload.data() + 24) / 1e7f;
            Latitude_deg = (float) GetU32Value(msg.Payload.data() + 28) / 1e7f;
            Altitude_m = (float) GetU32Value(msg.Payload.data() + 36) / 1e3f;
            Speed_mps = (float) GetU32Value(msg.Payload.data() + 60) / 1e3f;
            Course_deg = (float) GetU32Value(msg.Payload.data() + 64) / 1e5f;
            return true;
        }
    }
    return false;
}