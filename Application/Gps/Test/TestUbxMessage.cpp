//
// Created by PC on 25.05.2021.
//

#include <UbxMessage.h>
#include <gtest/gtest.h>
#include <vector>
// Demonstrate some basic assertions.

TEST(UbxMessage, Serialize)
{
    auto ubx = new UbxMessage(6, 8, std::vector<uint8_t>{0xC8, 0x00, 0x01, 0x00, 0x01, 0x00});
    auto expected = std::vector<uint8_t>{0xB5, 0x62, 0x06, 0x08, 0x06, 0x00, 0xC8, 0x00, 0x01, 0x00, 0x01, 0x00, 0xDE, 0x6A};
    auto actual = ubx->Serialize();
    // Expect equality.
    EXPECT_EQ(expected, actual);
}

TEST(UbxMessage, Deserialize)
{
    auto ubx = new UbxMessage();

    auto dataRaw = std::vector<uint8_t>{0xB5, 0x62, 0x06, 0x08, 0x06, 0x00, 0xC8, 0x00, 0x01, 0x00, 0x01, 0x00, 0xDE, 0x6A};
    auto expectedPayload = std::vector<uint8_t>{0xC8, 0x00, 0x01, 0x00, 0x01, 0x00};

    auto result = ubx->Deserialize(dataRaw);

    EXPECT_EQ(result, true);
    EXPECT_EQ(ubx->MsgClass, 0x06);
    EXPECT_EQ(ubx->MsgSubclass, 0x08);
    EXPECT_EQ(ubx->Payload, expectedPayload);
}

TEST(UbxMessage, DeserializeEmpty)
{
    auto ubx = new UbxMessage();
    auto dataRaw =
        std::vector<uint8_t>{};
    auto result = ubx->Deserialize(dataRaw);

    EXPECT_EQ(result, false);
}
