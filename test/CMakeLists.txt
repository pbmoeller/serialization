# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/releases/download/v1.16.0/googletest-1.16.0.tar.gz
# )
# FetchContent_MakeAvailable(googletest)

find_package(GTest REQUIRED)

add_executable(serialization-test
    "test_main.cpp"
    "v1.0/test_common.cpp"
    "v1.0/test_service_1.cpp"
    "v1.0/test_service_2.cpp"
)

target_include_directories(serialization-test
    PRIVATE
        "${PROJECT_SOURCE_DIR}/include"
        ${GTEST_INCLUDE_DIRS}
        ${GMOCK_INCLUDE_DIRS}
)

target_link_libraries(serialization-test 
    PRIVATE
        ${GTEST_LIBRARIES}
        serialization
        nlohmann_json::nlohmann_json
)
set_target_properties(serialization-test  
    PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
)
