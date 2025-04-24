cmake_minimum_required(VERSION 3.24)

project(serialization
    VERSION     0.1.0
    LANGUAGES   C CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz)
FetchContent_MakeAvailable(json)

add_subdirectory("src")

if(BUILD_TEST)
    add_subdirectory("test")
endif()
