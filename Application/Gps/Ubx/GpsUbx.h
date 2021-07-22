//
// Created by PC on 22.05.2021.
//
#pragma once


#include "Gps.h"
#include <cstdint>
#include <vector>
#include <array>
#include <map>
#include "UbxMessage.h"
class GpsUbx : public Gps
{
private:
    typedef double (GpsUbx::*math_method_t)(UbxMessage);
    typedef std::map<int, int> math_func_map_t;
    const math_func_map_t mapping = {
        {1,10},
    };
//    uint32_t ParseU32(std::vector<uint8_t> rawData);
    uint32_t ParseU32(uint8_t* rawData);

public:
    enum MsgClass
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
    };
    bool ParseMessage(std::vector<uint8_t> message);
//private:
    enum
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
    enum
    {
        ACK_ACK = 0x01,
        ACK_NAK = 0x00
    } AckClass;
    enum
    {
    
    } CfgClass;
    GpsUbx();
};
