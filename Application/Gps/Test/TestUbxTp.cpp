//
// Created by PC on 25.05.2021.
//

#include <UbxTp.h>
#include <gtest/gtest.h>
// Demonstrate some basic assertions.

TEST(UbxTp, Serialize)
{
    auto ubx = new UbxTp(6, 8, std::vector<uint8_t>{0xC8, 0x00, 0x01, 0x00, 0x01, 0x00});
    auto expected = std::vector<uint8_t>{0xB5, 0x62, 0x06, 0x08, 0x06, 0x00, 0xC8, 0x00, 0x01, 0x00, 0x01, 0x00, 0xDE, 0x6A};
    auto actual = ubx->Serialize();
    // Expect equality.
    EXPECT_EQ(expected, actual);
}

TEST(UbxTp, Deserialize)
{
    auto dataRaw = std::vector<uint8_t>{0xB5, 0x62, 0x06, 0x08, 0x06, 0x00, 0xC8, 0x00, 0x01, 0x00, 0x01, 0x00, 0xDE, 0x6A};
    auto expectedPayload = std::vector<uint8_t>{0xC8, 0x00, 0x01, 0x00, 0x01, 0x00};
    
    auto ubx = UbxTp::Deserialize(dataRaw);

    EXPECT_EQ(ubx.MsgClass, 0x06);
    EXPECT_EQ(ubx.MsgSubclass, 0x08);
    EXPECT_EQ(ubx.Payload, expectedPayload);
}
TEST(UbxTp, GetPackedData)
{
    auto ubx = UbxTp(1,2,{1,2,3,4});
    std::vector<uint8_t> expected = {1,2,1,2,3,4};
    EXPECT_EQ(ubx.GetPackedData(),expected);
}