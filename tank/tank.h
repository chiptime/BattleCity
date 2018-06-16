//
// Created by bruno on 14/06/18.
//
#include "../global.h"
#include <ncurses.h>


#ifndef BATTLECITY_TANK_H
#define BATTLECITY_TANK_H

#ifdef __cplusplus
extern "C" {
#endif
//Tank

//void tank1(int x, int y);

/*
struct Tanks {
    struct Position position;
    //double x = 0;
    //double y = 0;

};
Tanks positionTank(struct Tanks atank);
*/
void printTank(struct Tanks tank);
void resetCheck(int key, int &UP, int &LEFT, int &DOWN, int &RIGHT);
int direction(int UP, int LEFT, int DOWN, int RIGHT);
void maxCheck(int key, int &UP, int &LEFT, int &DOWN, int &RIGHT);
#ifdef __cplusplus
}
#endif

#endif //BATTLECITY_TANK_H
