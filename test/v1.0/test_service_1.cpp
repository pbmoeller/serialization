#include <gtest/gtest.h>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include <serialization/v1.0/common.hpp>
#include <serialization/v1.0/service_1.hpp>
#include <serialization/serializer.hpp>

TEST(SerializationTest, Service1Serialization) {
    ser::v1_0::Service1 original;
    original.name = "MyService";
    original.connection = ser::v1_0::Connection::Online;
    original.role = ser::v1_0::Role::Slave;
    original.protocol = ser::v1_0::Protocol::HTTP;
    original.location = {50.0, 10.0};

    json j = original;  // Serialisierung
    ser::v1_0::Service1 parsed = j.get<ser::v1_0::Service1>();  // Deserialisierung

    EXPECT_EQ(original.name, parsed.name);
    EXPECT_EQ(original.connection, parsed.connection);
    EXPECT_EQ(original.role, parsed.role);
    EXPECT_EQ(original.protocol, parsed.protocol);
    EXPECT_EQ(original.location.latitude, parsed.location.latitude);
    EXPECT_EQ(original.location.longitude, parsed.location.longitude);
}