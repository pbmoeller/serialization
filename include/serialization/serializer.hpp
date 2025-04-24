#ifndef SERIALIZATION_SERIALIZER_HPP
#define SERIALIZATION_SERIALIZER_HPP

#include <optional>
#include <concepts>
#include <string>
#include <type_traits>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace ser {

// Concept: Enum with toString/fromString
template<typename T>
concept StringSerializableEnum = requires(T t, std::string &str) {
    { toString(t, str) } -> std::same_as<void>;
    { fromString(t, str) } -> std::same_as<void>;
};

template<typename T>
concept JsonSerializable = requires(T t, json & j) {
    { toJson(t, j) } -> std::same_as<void>;
    { fromJson(t, j) } -> std::same_as<void>;
};

} // namespace ser

namespace nlohmann {

template<ser::StringSerializableEnum T>
struct adl_serializer<T> {
    static void to_json(json& j, const T &value) {
        std::string s;
        toString(value, s);
        j = s;
    }

    static void from_json(const json& j, T &value) {
        if(!j.is_string()) {
            throw std::invalid_argument(std::string("JSON value is not string. It is ") + j.type_name());
        }
        fromString(value, j.get<std::string>());
    }
};

template<ser::JsonSerializable T>
struct adl_serializer<T> {
    static void to_json(json &j, const T &value) {
        toJson(value, j);
    }

    static void from_json(const json &j, T &value) {
        fromJson(value, j);
    }
};

template<typename T>
struct adl_serializer<std::optional<T>> {
    static void to_json(json &j, const std::optional<T> &value) {
        if(value) {
            j = value.value();
        }
    }

    static void from_json(const json &j, std::optional<T> &value) {
        if(j.is_null()) {
            value = std::nullopt;
        } else {
            if constexpr(ser::StringSerializableEnum<T>) {
                T e;
                fromString(e, j.get<std::string>());
                value = e;
            } else {
                value = j.get<T>();
            }
        }
    }
};

template<typename T>
struct adl_serializer<std::vector<T>> {
    static void to_json(json &j, const std::vector<T> &value) {
        j = json::array();
        for(const auto& elem : value) {
            j.push_back(elem);
        }
    }

    static void from_json(const json &j, std::vector<T> &value) {
        if(j.is_null()) {
            value.clear();
        } else if(!j.is_array()) {
            throw std::invalid_argument(std::string("JSON value is not an array. It is ") + j.type_name());
        } else {
            value.clear();
            if constexpr(ser::StringSerializableEnum<T>) {
                for(const auto& item : j) {
                    T e;
                    fromString(e, item.get<std::string>());
                    value.push_back(e);
                }
            } else {
                for(const auto& item : j) {
                    value.push_back(item.get<T>());
                }
            }
        }
    }
};

} // namespace nlohmann

#endif // SERIALIZATION_SERIALIZER_HPP