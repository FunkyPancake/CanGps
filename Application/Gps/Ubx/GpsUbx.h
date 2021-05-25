//
// Created by PC on 22.05.2021.
//

#ifndef CANGPS_GPSUBX_H
#define CANGPS_GPSUBX_H

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
    std::vector<uint8_t> BuildMessage(MsgClass msgClass,
                                      uint8_t subClass,
                                      uint16_t length,
                                      std::vector<uint8_t> payload);
    bool ParseMessage(std::vector<uint8_t> message);

private:
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
    
    void ParsePayload(std::vector<uint8_t> &message);
    
    bool CheckChecksum(std::vector<uint8_t> &message);
    
    bool CheckHeader(std::vector<uint8_t> &message);
    
    bool CheckLength(std::vector<uint8_t> &message);
    
    std::array<uint8_t,2> CalcChecksum(std::vector<uint8_t> &payload);
};

#endif//CANGPS_GPSUBX_H
