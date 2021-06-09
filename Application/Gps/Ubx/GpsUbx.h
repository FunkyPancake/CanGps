//
// Created by PC on 22.05.2021.
//
#pragma once


#include "Gps.h"
#include <cstdint>
#include <vector>
#include <array>

class GpsUbx : public Gps
{
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
        SEC = 0x027,
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
        NAV_HPPOSLLH
    } NavClass;
    enum
    {
        ACK_ACK = 0x01,
        ACK_NAK = 0x00
    } AckClass;
    enum
    {
    
    } CfgClass;
    
    
};
