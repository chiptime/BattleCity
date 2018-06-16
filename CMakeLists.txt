cmake_minimum_required(VERSION 3.9)
project(battlecity)

set(CMAKE_CXX_STANDARD 17)

add_executable(battlecity battlecity.cpp mapa/mapa.h ncurses/ncurses.cpp ncurses/ncurses.h mapa/mapa.cpp tank/tank.cpp tank/tank.h global.h global.cpp bullet.cpp)

target_link_libraries(battlecity ncursesw)