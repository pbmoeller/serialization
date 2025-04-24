#include <gtest/gtest.h>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include <serialization/v1.0/common.hpp>
#include <serialization/v1.0/service_2.hpp>
#include <serialization/serializer.hpp>

TEST(optional, protocol)
{
    std::optional<ser::v1_0::Protocol> p = ser::v1_0::Protocol::HTTP;

    json j = p;

    std::optional<ser::v1_0::Protocol> p2 = j.get<std::optional<ser::v1_0::Protocol>>();


}

TEST(Service2SerializationTest, Service2OptionalSerialization) {
    ser::v1_0::Service2 original;
    original.name = "Service2";
    original.alias_name = std::make_optional<std::string>("MyAlias");
    original.preferred_protocol = ser::v1_0::Protocol::HTTP;

    json j = original;  // Serialisierung
    auto s = j.dump();
    ser::v1_0::Service2 parsed = j.get<ser::v1_0::Service2>();  // Deserialisierung

    EXPECT_EQ(original.name, parsed.name);
    EXPECT_EQ(original.alias_name, parsed.alias_name);
    EXPECT_EQ(original.preferred_protocol, parsed.preferred_protocol);
}

TEST(Service2SerializationTest, Service2OptionalEmpty) {
    ser::v1_0::Service2 original;
    original.name = "Service2";
    original.alias_name = std::nullopt;  // Optional leer
    original.preferred_protocol = std::nullopt;

    json j = original;  // Serialisierung
    ser::v1_0::Service2 parsed = j.get<ser::v1_0::Service2>();  // Deserialisierung

    EXPECT_EQ(original.name, parsed.name);
    EXPECT_EQ(original.alias_name, parsed.alias_name);
    EXPECT_EQ(original.preferred_protocol, parsed.preferred_protocol);
}

TEST(Service2SerializationTest, Service2OptionalNullInJson) {
    json j = R"({"name": "Service2", "alias_name": null, "preferred_protocol": null, "clients": null, "protocols": null})"_json;

    ser::v1_0::Service2 parsed = j.get<ser::v1_0::Service2>();  // Deserialisierung

    EXPECT_EQ(parsed.name, "Service2");
    EXPECT_EQ(parsed.alias_name, std::nullopt);
    EXPECT_EQ(parsed.preferred_protocol, std::nullopt);
}

TEST(Service2SerializationTest, Service2Serialization) {
    ser::v1_0::Service2 original = {
        {"client1", "client2", "client3"},
        {ser::v1_0::Protocol::HTTP, ser::v1_0::Protocol::MQTT},
        "Service Name",
        "Alias Name",
        ser::v1_0::Protocol::HTTP
    };

    json j = original;
    ser::v1_0::Service2 parsed = j.get<ser::v1_0::Service2>();

    EXPECT_EQ(original.name, parsed.name);
    EXPECT_EQ(original.alias_name, parsed.alias_name);
    EXPECT_EQ(original.preferred_protocol, parsed.preferred_protocol);
    EXPECT_EQ(original.clients, parsed.clients);
}

TEST(Service2SerializationTest, Service2EmptyOptionalSerialization) {
    ser::v1_0::Service2 original = {
        {"client1", "client2"},
        //{ser::v1_0::Protocol::HTTP, ser::v1_0::Protocol::MQTT},
        {},
        "Service Name",
        std::nullopt,
        std::nullopt
    };

    json j = original;
    ser::v1_0::Service2 parsed = j.get<ser::v1_0::Service2>();

    EXPECT_EQ(original.name, parsed.name);
    EXPECT_EQ(original.alias_name, parsed.alias_name);
    EXPECT_EQ(original.preferred_protocol, parsed.preferred_protocol);
    EXPECT_EQ(original.clients, parsed.clients);
}