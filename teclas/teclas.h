//
// Created by bruno on 17/06/18.
//

#ifndef BATTLECITY_TECLAS_H
#define BATTLECITY_TECLAS_H

#include "../global/global.h"
#include "../battlecity.h"
#include "../tank/tank.h"
#include "../mapa/mapa.h"
#include "../bullet/bullet.h"

#ifdef __cplusplus
extern "C" {
#endif

int teclas(struct Tanks *move, Bullets *position_Bullet);

#ifdef __cplusplus
}
#endif

#endif //BATTLECITY_TECLAS_H
