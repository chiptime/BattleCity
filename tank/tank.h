//
// Created by bruno on 14/06/18.
//
#include "../global/global.h"



#ifndef BATTLECITY_TANK_H
#define BATTLECITY_TANK_H

#ifdef __cplusplus
extern "C" {
#endif
//Tank
void printTank(struct Tanks tank);
void resetCheck(int key, int &UP, int &LEFT, int &DOWN, int &RIGHT);
int direction(int UP, int LEFT, int DOWN, int RIGHT);
void maxCheck(int key, int &UP, int &LEFT, int &DOWN, int &RIGHT);
#ifdef __cplusplus
}
#endif

#endif //BATTLECITY_TANK_H
