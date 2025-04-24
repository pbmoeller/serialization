#ifndef SERIALIZATION_V1_0_COMMON_HPP
#define SERIALIZATION_V1_0_COMMON_HPP

#include "serialization/types.hpp"

#include <nlohmann/json_fwd.hpp>
using json = nlohmann::json;

namespace ser {
namespace v1_0 {

enum class Connection
{
    Unknown,
    Online,
    Offline,
};

void toString(const Connection &value, std::string &str);
void fromString(Connection &value, const std::string &str);

enum class Role
{
    Master,
    Slave,
};

void toString(const Role &value, std::string &str);
void fromString(Role &value, const std::string &str);

enum class Protocol
{
    TCP,
    MQTT,
    UDP,
    HTTP,
};

void toString(const Protocol &value, std::string &str);
void fromString(Protocol &value, const std::string &str);

struct Location
{
    double latitude{};
    double longitude{};
};

void toJson(const Location &value, json &j);
void fromJson(Location &value, const json &j);

} // namespace v1_0
} // namespace ser

#endif // SERIALIZATION_V1_0_COMMON_HPP
