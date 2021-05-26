//
// Created by PC on 26.05.2021.
//

#include "UbxMessage.h"

#include <utility>

std::vector<uint8_t> UbxMessage::Serialize()
{
    std::vector<uint8_t> header{0xB5, 0x62};
    std::vector<uint8_t> data{ static_cast<uint8_t>(MsgClass), MsgSubclass,static_cast<uint8_t>(Payload.size() & 0xFF), static_cast<uint8_t>(Payload.size() >> 8)};
    data.insert(data.end(), Payload.begin(), Payload.end());
    auto checksum = CalcChecksum(data);
    
    data.insert(data.begin(), header.begin(), header.end());
    data.insert(data.end(), checksum.begin(), checksum.end());
    return data;
}

bool UbxMessage::Deserialize(std::vector<uint8_t> data)
{
    auto validFrame = false;
    if (data.size() > 8 && (data[0] == 0xB5) && (data[1] == 0x62))
    {
        if (CheckChecksum(data))
        {
            MsgClass = static_cast<MsgClassEnum>(data[2]);
            MsgSubclass = data[3];
            Payload = {data.begin() + 6, data.end()-2};
            validFrame = true;
        }
        
    }
    return validFrame;
}

UbxMessage::UbxMessage()
{

}

UbxMessage::UbxMessage(UbxMessage::MsgClassEnum msgClass, uint8_t msgSubclass, std::vector<uint8_t> payload)
{
    MsgClass = msgClass;
    MsgSubclass = msgSubclass;
    Payload = std::move(payload);
}

bool UbxMessage::CheckChecksum(std::vector<uint8_t> &data)
{
    uint8_t cka = 0, ckb = 0;
    auto len = data.size();
    for (auto i = 2u; (len - 2 )> i; i++)
    {
        cka += data[i];
        ckb += cka;
    }
    return cka == data[len - 2] && ckb == data[len - 1];
}

std::array<uint8_t, 2> UbxMessage::CalcChecksum(std::vector<uint8_t> &data)
{
    uint8_t cka = 0, ckb = 0;
    for (auto b : data)
    {
        cka += b;
        ckb += cka;
    }
    return {cka, ckb};
}
