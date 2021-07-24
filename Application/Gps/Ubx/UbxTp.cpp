//
// Created by PC on 26.05.2021.
//

#include "UbxTp.h"

std::vector<uint8_t> UbxTp::Serialize()
{
    std::vector<uint8_t> data(Payload.size() + 8, 0);
    std::vector<uint8_t> initData{
        0xB5,
        0x62,
        MsgClass,
        MsgSubclass,
        static_cast<uint8_t>(Payload.size()),
        static_cast<uint8_t>(Payload.size() >> 8)
    };
    std::copy(initData.begin(), initData.end(), data.begin());
    std::copy(Payload.begin(), Payload.end(), data.begin() + 6);
    
    auto checksum = CalcChecksum(data);
    
    std::copy(checksum.begin(), checksum.end(), data.end() - 2);
    
    return data;
}

UbxTp UbxTp::Deserialize(std::vector<uint8_t> data)
{
    auto obj = UbxTp();
    if (data.size() > 8 && (data[0] == 0xB5) && (data[1] == 0x62))
    {
        if (CheckChecksum(data))
        {
            obj.MsgClass = data[2];
            obj.MsgSubclass = data[3];
            obj.Payload = {data.begin() + 6, data.end() - 2};
        }
    }
    return obj;
}

UbxTp::UbxTp()
{
    MsgClass = 0;
    MsgSubclass = 0;
    Payload = std::vector<uint8_t>{};
}

UbxTp::UbxTp(uint8_t msgClass, uint8_t msgSubclass, std::vector<uint8_t> payload)
{
    MsgClass = msgClass;
    MsgSubclass = msgSubclass;
    Payload = std::move(payload);
}

bool UbxTp::CheckChecksum(std::vector<uint8_t> &data)
{
    uint8_t cka = 0, ckb = 0;
    auto len = data.size();
    for (auto i = 2u; (len - 2) > i; i++)
    {
        cka += data[i];
        ckb += cka;
    }
    return cka == data[len - 2] && ckb == data[len - 1];
}

std::array<uint8_t, 2> UbxTp::CalcChecksum(std::vector<uint8_t> &data)
{
    uint8_t cka = 0, ckb = 0;
    for (auto i = 2u; (data.size() - 2) > i; i++)
    {
        cka += data[i];
        ckb += cka;
    }
    return {cka, ckb};
}

std::vector<uint8_t> UbxTp::GetPackedData()
{
    std::vector<uint8_t> rawData(Payload.size() + 2);
    rawData[0] = MsgClass;
    rawData[1] = MsgSubclass;
    std::copy(Payload.begin(), Payload.end(), rawData.begin() + 2);
    return rawData;
}
