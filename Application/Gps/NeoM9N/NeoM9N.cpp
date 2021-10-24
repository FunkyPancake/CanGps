//
// Created by PC on 24.05.2021.
//

#include <UbxTp.h>
#include <UbxNavPvt.h>
#include "NeoM9N.h"

void NeoM9N::Config()
{
//    ValSet<uint32_t>(CfgUart1Baudrate,115200);
    _com->SetBaudrate(115200);
    ValSet<bool>(CfgUart1OutProtNmea, false);
    ValSet<bool>(CfgUart1OutProtUbx, true);
    ValSet<uint8_t>(CfgNavSpgDynmodel, 4);
    ValSet<uint8_t>(CfgMsgoutUbxNavPvtUart1, 1);
    ValSet<uint16_t>(CfgRateMeas, 40);
}

void NeoM9N::GetData()
{
    auto msg = UbxNavPvt(_com);
    if(msg.GetFrame())
    {
        SateliteNumber = msg.SateliteNumber;
        Longitude_deg = msg.Longitude_deg;
        Latitude_deg = msg.Latitude_deg;
        Altitude_m = msg.Altitude_m;
        Speed_mps = msg.Speed_mps;
        Course_deg = msg.Course_deg;
    }
}



NeoM9N::NeoM9N(ICom *com) : UbxCfg(com), IGps()
{
}
