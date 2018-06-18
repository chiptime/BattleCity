cmake_minimum_required(VERSION 3.9)
project(battlecity)

set(CMAKE_CXX_STANDARD 17)

add_executable(battlecity battlecity.cpp mapa/mapa.h ncurses/ncurses.cpp ncurses/ncurses.h mapa/mapa.cpp tank/tank.cpp tank/tank.h global/global.h global/global.cpp bullet/bullet.cpp bullet/bullet.h teclas/teclas.cpp teclas/teclas.h battlecity.h)

target_link_libraries(battlecity ncursesw)