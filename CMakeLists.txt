cmake_minimum_required(VERSION 4.0)

project(TestMod VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(libraries/RED4ext)
add_subdirectory(libraries/RedLib)

set(LIBRARIES 
    RED4ext.SDK 
    RedLib
)

set(LIBRARY_PATHS
    "${CMAKE_CURRENT_SOURCE_DIR}/libraries/RED4ext"
    "${CMAKE_CURRENT_SOURCE_DIR}/libraries/RedLib"
)

add_library(TestMod SHARED src/main.cpp)
add_compile_definitions(NOMINMAX)


foreach(LIB_PATH ${LIBRARY_PATHS})
    target_include_directories(TestMod INTERFACE ${LIB_PATH}/include)
    target_include_directories(TestMod INTERFACE ${LIB_PATH}/vendor)
endforeach()

#target_include_directories(RedLib INTERFACE include)


#target_include_directories(TestMod PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/libraries/RED4ext/include)
#target_include_directories(TestMod PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/libraries/RED4ext/vendor)


target_link_libraries(TestMod PRIVATE ${LIBRARIES})
