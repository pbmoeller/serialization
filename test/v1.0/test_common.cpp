#include <gtest/gtest.h>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include <serialization/v1.0/common.hpp>

TEST(EnumSerializationTest, ProtocolRoundTrip) {
    ser::v1_0::Protocol proto = ser::v1_0::Protocol::MQTT;
    json j = proto;
    ser::v1_0::Protocol parsed = j.get<ser::v1_0::Protocol>();
    EXPECT_EQ(proto, parsed);
}