#include "serialization/v1.0/common.hpp"
#include "serialization/serializer.hpp"

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include <stdexcept>

namespace ser {
namespace v1_0 {

void toString(const Connection &value, std::string &str)
{
    switch(value) {
        case Connection::Unknown:   str = "Unknown";    break;
        case Connection::Online:    str = "Online";     break;
        case Connection::Offline:   str = "Offline";    break;
        default:
            throw std::invalid_argument("Invalid Connection value");
    }
}

void fromString(Connection &value, const std::string &str)
{
    if(str == "Unknown")        value = Connection::Unknown;
    else if(str == "Online")    value = Connection::Online;
    else if(str == "Offline")   value = Connection::Offline;
    else throw std::invalid_argument("Invalid Connection string: " + str);
}

void toString(const Role &value, std::string &str)
{
    switch(value) {
        case Role::Master:  str = "Master"; break;
        case Role::Slave:   str = "Slave";  break;
        default:
            throw std::invalid_argument("Invalid Role value");
    }
}

void fromString(Role &value, const std::string &str)
{
    if(str == "Master")         value = Role::Master;
    else if(str == "Slave")     value = Role::Slave;
    else throw std::invalid_argument("Invalid Role string: " + str);
}

void toString(const Protocol &value, std::string &str)
{
    switch(value) {
        case Protocol::TCP:     str = "TCP";    break;
        case Protocol::MQTT:    str = "MQTT";   break;
        case Protocol::UDP:     str = "UDP";    break;
        case Protocol::HTTP:    str = "HTTP";   break;
        default:
            throw std::invalid_argument("Invalid Protocol value");
    }
}

void fromString(Protocol &value, const std::string &str)
{
    if(str == "TCP")        value = Protocol::TCP;
    else if(str == "MQTT")  value = Protocol::MQTT;
    else if(str == "UDP")   value = Protocol::UDP;
    else if(str == "HTTP")  value = Protocol::HTTP;
    else throw std::invalid_argument("Invalid Protocol string: " + str);
}

void toJson(const Location &value, json &j)
{
    j["latitude"] = value.latitude;
    j["longitude"] = value.longitude;
}

void fromJson(Location &value, const json &j)
{
    j.at("latitude").get_to(value.latitude);
    j.at("longitude").get_to(value.longitude);
}

} // namespace v1_0
} // namespace ser
