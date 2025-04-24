set(HEADER
    # common
    "${PROJECT_SOURCE_DIR}/include/serialization/types.hpp"
    "${PROJECT_SOURCE_DIR}/include/serialization/serializers.hpp"

    # v1.0
    "${PROJECT_SOURCE_DIR}/include/serialization/v1.0/common.hpp"
    "${PROJECT_SOURCE_DIR}/include/serialization/v1.0/service_1.hpp"
    "${PROJECT_SOURCE_DIR}/include/serialization/v1.0/service_2.hpp"
)

add_library(serialization SHARED
    "v1.0/common.cpp"
    "v1.0/service_1.cpp"
    "v1.0/service_2.cpp"
)

target_include_directories(serialization
    PUBLIC
        "${PROJECT_SOURCE_DIR}/include/"
)

target_link_libraries(serialization
    PRIVATE
        nlohmann_json::nlohmann_json
)
