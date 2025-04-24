#include "serialization/v1.0/service_1.hpp"
#include "serialization/serializer.hpp"

namespace ser {
namespace v1_0 {

void toJson(const Service1 &value, json &j)
{
    j["name"] = value.name;
    j["connection"] = value.connection;
    j["role"] = value.role;
    j["protocol"] = value.protocol;
    j["location"] = value.location;
}

void fromJson(Service1 &value, const json &j)
{
    j.at("name").get_to(value.name);
    j.at("connection").get_to(value.connection);
    j.at("role").get_to(value.role);
    j.at("protocol").get_to(value.protocol);
    j.at("location").get_to(value.location);
}

} // namespace v1_0
} // namespace ser