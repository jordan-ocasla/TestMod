cmake_minimum_required(VERSION 4.0)

project(TestMod VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TestMod src/main.cpp)

add_subdirectory(libraries/RED4ext)
target_include_directories(TestMod INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/libraries/RED4ext/include")
target_include_directories(TestMod INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/libraries/RED4ext/vendor")

target_link_libraries(TestMod PRIVATE RED4ext.SDK)
