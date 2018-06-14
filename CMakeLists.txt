cmake_minimum_required(VERSION 3.9)
project(battlecity)

set(CMAKE_CXX_STANDARD 17)

add_executable(battlecity battlecity.cpp)

target_link_libraries(battlecity ncursesw)