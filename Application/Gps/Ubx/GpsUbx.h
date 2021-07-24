//
// Created by PC on 22.05.2021.
//
#pragma once

#include "Gps.h"
#include <cstdint>
#include <vector>
#include <array>
#include "UbxTp.h"
#include <ICom.h>

class GpsUbx
{
private:
    bool CheckAck(UbxTp &msg, uint8_t msgClass, uint8_t msgSubclass);

protected:
    ICom *_com;
    typedef enum
    {
        CfgUart1InProtUbx = 0x10730001UL,
        CfgUart1OutProtUbx = 0x10740001UL,
        CfgUart1OutProtNmea = 0x10740002UL,
        CfgMsgoutUbxNavPvtUart1 = 0x20910007UL,
        CfgRateMeas = 0x30210001UL,
        CfgUart1Baudrate = 0x40520001UL,
        CfgOdoUseOdo = 0x10220001UL,
        CfgOdoProfile = 0x20220005UL,
    }UbxValRegisters;
    std::vector<uint8_t> ReadMessage();
    
    typedef enum
    {
        Ram = 1, Bbr = 2, Flash = 3
    } LayerLevel;
    typedef enum
    {
        NAV = 0x01,
        RXM = 0x02,
        INF = 0x04,
        ACK = 0x05,
        CFG = 0x06,
        MON = 0x0A,
        AID = 0x0B,
        TIM = 0x0D,
        ESF = 0x10,
        MGA = 0x13,
        LOG = 0x21,
        SEC = 0x27,
        HNR = 0x28
    } MsgClass;
    typedef enum
    {
        NAV_AOPSTATUS,
        NAV_ATT,
        NAV_CLOCK,
        NAV_COV,
        NAV_DGPS,
        NAV_DOP,
        NAV_EELL,
        NAV_EOE,
        NAV_GEOFENCE,
        NAV_HPPOSECEF,
        NAV_HPPOSLLH,
        NAV_PVT = 7,
    } NavClass;
    
    template<typename T> bool ValSet(uint32_t key, T data, LayerLevel layer = Ram)
    {
        std::vector<uint8_t> payload(8 + sizeof(T), 0);
        payload[1] = layer;
        *(uint32_t *) (payload.data() + 4) = key;
        *(T *) (payload.data() + 8) = data;
        
        std::vector<uint8_t> req = UbxTp(GpsUbx::CFG, 0x8a, payload).Serialize();
        _com->WriteBytes(req);
        auto resp = UbxTp::Deserialize(_com->ReadBytes(10));
        return CheckAck(resp, GpsUbx::CFG, 0x8a);
        
    }
    
    explicit GpsUbx(ICom *com);
};
