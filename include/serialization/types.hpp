#ifndef SERIALIZATION_TYPES_HPP
#define SERIALIZATION_TYPES_HPP

#include <string>
#include <cstdint>

namespace ser {

// XML Types
namespace xs {

using Boolean           = bool;
using String            = std::string;
using Short             = std::int16_t;
using UnsignedShort     = std::uint16_t;

} // namespace xs

} // namespace ser

#endif // SERIALIZATION_TYPES_HPP
