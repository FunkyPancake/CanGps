//
// Created by PC on 24.05.2021.
//

#include <UbxMessage.h>
#include "NeoM9N.h"

void NeoM9N::Config()
{
    {
//        std::vector<uint8_t> data = UbxMessage(UbxMessage::CFG, 0x8a, {
//            0x00, 0x01, 0x00, 0x00,
//            0x01, 0x00, 0x52, 0x40,
//            0x00, 0x96, 0x00, 0x00
//        }).Serialize();
//        _com->WriteBytes(data);
//        auto a = _com->ReadBytes(10);
    }
    {
        std::vector<uint8_t> data = UbxMessage(UbxMessage::CFG, 0x8a, {
            0x00, 0x01, 0x00, 0x00,
            0x01, 0x00, 0x73, 0x10,
            0x01
        }).Serialize();
        _com->WriteBytes(data);
        auto a = _com->ReadBytes(10);
    }
    {
        std::vector<uint8_t> data = UbxMessage(UbxMessage::CFG, 0x8a, {
            0x00, 0x01, 0x00, 0x00,
            0x01, 0x00, 0x74, 0x10,
            0x01
        }).Serialize();
        _com->WriteBytes(data);
        auto a = _com->ReadBytes(10);
    }
    {
        std::vector<uint8_t> data = UbxMessage(UbxMessage::CFG, 0x8a, {
            0x00, 0x01, 0x00, 0x00,
            0x02, 0x00, 0x74, 0x10,
            0x00
        }).Serialize();
        _com->WriteBytes(data);
        auto a = _com->ReadBytes(10);
    }
    {
        std::vector<uint8_t> data = UbxMessage(UbxMessage::CFG, 0x8a, {
            0x00, 0x01, 0x00, 0x00,
            0x01, 0x00, 0x21, 0x30,
            0x28,0x00
        }).Serialize();
        _com->WriteBytes(data);
        auto a = _com->ReadBytes(10);
    }
//    _com->SetBaudrate(460800);
}
bool NeoM9N::GetData()
{
    std::vector<uint8_t> data = UbxMessage(UbxMessage::NAV,7,{}).Serialize();
    _com->WriteBytes(data);
    auto rdata = _com->ReadBytes(100);
    UbxMessage().Deserialize(rdata);
    return true;
}

//NeoM9N::NeoM9N(ICom *com) : GpsUbx()
NeoM9N::NeoM9N(LpUart *com) : GpsUbx()
{
    _com = com;
}
