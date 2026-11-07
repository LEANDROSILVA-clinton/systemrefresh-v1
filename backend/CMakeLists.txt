cmake_minimum_required(VERSION 3.20)
project(WeatherClient LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
add_subdirectory()   \\ adicionar a pasta local do gtest dentro do parenteses

add_executable(httpapi httpapi.cpp)
target_link_libraries(httpapi PRIVATE cpr::cpr nlohmann_json::nlohmann_json)
