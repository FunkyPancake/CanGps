//
// Created by PC on 26.05.2021.
//

#pragma once

#include <array>
#include <cstdint>
#include <vector>

class UbxTp
{
private:
    static bool CheckChecksum(std::vector<uint8_t> &data);
    static std::array<uint8_t, 2> CalcChecksum(std::vector<uint8_t> &data);
public:
    uint8_t MsgClass;
    uint8_t MsgSubclass;
    std::vector<uint8_t> Payload;
    UbxTp();
    UbxTp(uint8_t msgClass, uint8_t msgSubclass, std::vector<uint8_t> payload);
    std::vector<uint8_t> Serialize();
    static UbxTp Deserialize(std::vector<uint8_t> data);
    std::vector<uint8_t> GetPackedData();
};

