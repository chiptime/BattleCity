#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//for mygetch
#include <unistd.h>

//For UTF-8
#include <locale.h>
//Local Files
#include "global/global.h"
#include "mapa/mapa.h"
#include "ncurses/ncurses.h"
#include "tank/tank.h"
#include "bullet/bullet.h"
#include "battlecity.h"
#include "teclas/teclas.h"


int main() {
    int dir = 0;
    setlocale(LC_ALL,"");
    struct Tanks tank1 = {7,7};
    struct Bullets bullet = {0,0};

    iniciar_Curses();
    //getmaxyx(stdscr,row,col);

    while(teclas(&tank1, &bullet) != KEY_BREAK){
        clear();
        printMap();
        printTank(tank1);
        dir = teclas(&tank1, &bullet);
        printBullet(tank1,&bullet, bullet, dir);
        DEBUG(40-10,0,"dir is %i", dir);
        usleep(20000);
    }
    finalizar_Curses();
    return EXIT_SUCCESS;
}

