#ifndef SERIALIZATION_V1_0_SERVICE_1_HPP
#define SERIALIZATION_V1_0_SERVICE_1_HPP

#include "serialization/v1.0/common.hpp"

#include <string>

namespace ser {
namespace v1_0 {

struct Service1 {
    std::string name;
    Connection connection{};
    Role role{};
    Protocol protocol{};
    Location location{};
};

void toJson(const Service1 &value, json &j);
void fromJson(Service1 &value, const json &j);

} // namespace v1_0
} // namespace ser

#endif // SERIALIZATION_V1_0_SERVICE_1_HPP
