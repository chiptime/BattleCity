//
// Created by bruno on 14/06/18.
//

#ifndef BATTLECITY_TANK_H
#define BATTLECITY_TANK_H

#ifdef __cplusplus
extern "C" {
#endif
//Tank
struct Tanks {
    double x = 0;
    double y = 0;
};

void tank1(int x, int y);
Tanks positionTank(struct Tanks atank);


#ifdef __cplusplus
}
#endif

#endif //BATTLECITY_TANK_H
