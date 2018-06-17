//
// Created by bruno on 17/06/18.
//

#ifndef BATTLECITY_BULLET_H
#define BATTLECITY_BULLET_H

#include <ncurses.h>
#include "global.h"


#ifdef __cplusplus
extern "C" {
#endif
void tankToBullet(struct Tanks atank, struct Bullets *bullet);
void printBullet(struct Tanks tbullet, struct Bullets *position_Bullet, struct Bullets position, int checkDirection);

#ifdef __cplusplus
}
#endif
#endif //BATTLECITY_BULLET_H
