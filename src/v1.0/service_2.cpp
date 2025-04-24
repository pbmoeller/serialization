#include "serialization/v1.0/service_2.hpp"
#include "serialization/serializer.hpp"

namespace ser {
namespace v1_0 {

void toJson(const Service2 &value, json &j)
{
    j["name"] = value.name;
    j["alias_name"] = value.alias_name;
    j["preferred_protocol"] = value.preferred_protocol;
    j["clients"] = value.clients;
    j["protocols"] = value.protocols;
}

void fromJson(Service2 &value, const json &j)
{
    j.at("name").get_to(value.name);
    j.at("alias_name").get_to(value.alias_name);
    j.at("preferred_protocol").get_to(value.preferred_protocol);
    j.at("clients").get_to(value.clients);
    j.at("protocols").get_to(value.protocols);
}

} // namespace v1_0
} // namespace ser