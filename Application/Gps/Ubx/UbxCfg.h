//
// Created by PC on 22.05.2021.
//
#pragma once

#include <cstdint>
#include <vector>
#include <array>
#include "UbxTp.h"
#include <ICom.h>

class UbxCfg
{
private:
    const uint8_t MsgClass = 0x06;
    const uint8_t MsgSubclass = 0x8a;

protected:
    ICom *_com;
    typedef enum
    {
        CfgOdoUseOdo = 0x10220001UL,
        CfgUart1InProtUbx = 0x10730001UL,
        CfgUart1OutProtUbx = 0x10740001UL,
        CfgUart1OutProtNmea = 0x10740002UL,
        CfgNavSpgDynmodel = 0x20110021,
        CfgOdoProfile = 0x20220005UL,
        CfgMsgoutUbxNavPvtUart1 = 0x20910007UL,
        CfgRateMeas = 0x30210001UL,
        CfgUart1Baudrate = 0x40520001UL,
    } UbxValRegisters;
    
    typedef enum
    {
        Ram = 1, Bbr = 2, Flash = 3
    } LayerLevel;

    
    template<typename T> bool ValSet(uint32_t key, T data, LayerLevel layer = Ram)
    {
        std::vector<uint8_t> payload(8 + sizeof(T), 0);
        payload[1] = layer;
        *(uint32_t *) (payload.data() + 4) = key;
        *(T *) (payload.data() + 8) = data;
        
        std::vector<uint8_t> req = UbxTp(MsgClass, MsgSubclass, payload).Serialize();
        _com->WriteBytes(req);
        auto resp = UbxTp::Deserialize(_com->ReadBytes(10));
        return resp.CheckAck(MsgClass, MsgSubclass);
        
    }
    
    explicit UbxCfg(ICom *com);
};
