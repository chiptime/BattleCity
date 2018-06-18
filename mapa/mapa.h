//
// Created by bruno on 14/06/18.
//
#ifndef BATTLECITY_MAPA_H
#define BATTLECITY_MAPA_H

//#define xInicio 10
//#define yInicio 10
//#define N 50
//#define M 50

#include "../global/global.h"

#define fila  27
#define columna 42

#define minf 0
#define minc 0
#define maxf (fila-1)
#define maxc (columna-1)

#define BLOCK "\u2588"

#ifdef __cplusplus
extern "C" {
#endif

//Funciones del juego
void printMap();

#ifdef __cplusplus
}
#endif

#endif //BATTLECITY_MAPA_H
