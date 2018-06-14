//
// Created by bruno on 14/06/18.
//

#include "tank.h"
#include <ncurses.h>
#include "global.h"


void tank1(int x, int y) {
    int algo;

    algo = mvprintw(y, x,"H");

    if(ERR == algo){
        mvprintw( row -2,0,"This screen has %d rows and %d columns\n", row , col );
        mvprintw( row -1,0,"errah, %i,%i no es una direccio valida\n", y, x);
    }
    mvprintw( row -1,0,"tank 1 está en, %i,%i", y, x);
    mvprintw( row -2,0,"tank 1 está en, %i,%i", y, x);

    refresh();
}

Tanks positionTank(struct Tanks atank){
    return atank;
}

