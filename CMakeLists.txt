cmake_minimum_required(VERSION 3.10)

project(myproject) 

set(CMAKE_CXX_STANDARD 11)

add_executable(myproject main.cpp DotMatrix.cpp Polygon.cpp BSP.cpp utils.cpp)

target_include_directories(myproject PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})