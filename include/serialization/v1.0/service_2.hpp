#ifndef SERIALIZATION_V1_0_SERVICE_2_HPP
#define SERIALIZATION_V1_0_SERVICE_2_HPP

#include "serialization/v1.0/common.hpp"

#include <string>
#include <vector>
#include <optional>

namespace ser {
namespace v1_0 {

struct Service2 {

    static constexpr size_t kMin_clients = 1;
    static constexpr size_t kMax_clients = 8;

    std::vector<std::string> clients;
    std::vector<Protocol> protocols;

    std::string name;
    std::optional<std::string> alias_name;
    std::optional<Protocol> preferred_protocol;
};

void toJson(const Service2 &value, json &j);
void fromJson(Service2 &value, const json &j);

} // namespace v1_0
} // namespace ser

#endif // SERIALIZATION_V1_0_SERVICE_2_HPP
