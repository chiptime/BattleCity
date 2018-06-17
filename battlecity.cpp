#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//for mygetch
#include <unistd.h>
#include <ncurses.h>
//For UTF-8
#include <locale.h>
//Local Files
#include "mapa/mapa.h"
#include "ncurses/ncurses.h"
#include "tank/tank.h"
#include "global.h"
#include "bullet.h"
///////////////// DEBUGGING
int row,col;
////////////////////////////////////////////////////////////////////////////////////////////
int teclas(struct Tanks *move, Bullets *position_Bullet){
    int static checkDirection = 0;
    int static checkRIGHT = 0;
    int static checkLEFT = 0;
    int static checkUP = 0;
    int static checkDOWN = 0;
    int arrow;
    int static lastKey = 0;
    arrow = getch();
    if(arrow != -1)
        lastKey = arrow;
    DEBUG(row-5,0,"arrow es %i, y lastkey es %i", arrow, lastKey);
    DEBUG(row-8,0,"checkDirection is %i ", checkDirection);
    DEBUG(row-6,0,"checkRIGHT: %i, checkDOWN: %i, checkLEFT: %i, checkUP: %i",
          checkRIGHT,     checkDOWN,     checkLEFT,     checkUP);
    switch(arrow){
        case KEY_UP:
            resetCheck(arrow, checkUP, checkLEFT, checkDOWN, checkRIGHT);
            if(direction(checkUP, checkLEFT, checkDOWN, checkRIGHT) == 1){
                (*move).position.y -= 1;
                if((*move).position.y < minf + 1 )//((minf-1) ))//Up limit 9
                    (*move).position.y += 1;
            }
            maxCheck(arrow, checkUP, checkLEFT, checkDOWN, checkRIGHT);
            break;

        case KEY_LEFT:
            resetCheck(arrow, checkUP, checkLEFT, checkDOWN, checkRIGHT);
            if(direction(checkUP, checkLEFT, checkDOWN, checkRIGHT) == 2){
                (*move).position.x -= 1;
                if((*move).position.x < minc + 1 )//Left limit 9
                    (*move).position.x += 1;
            }
            maxCheck(arrow, checkUP, checkLEFT, checkDOWN, checkRIGHT);
            break;

        case KEY_DOWN:
            resetCheck(arrow, checkUP, checkLEFT, checkDOWN, checkRIGHT);
            if(direction(checkUP, checkLEFT, checkDOWN, checkRIGHT) == 3){
                (*move).position.y += 1;
                if( (*move).position.y > maxf-1 )// Down limit -15
                    (*move).position.y -= 1;
            }
            maxCheck(arrow, checkUP, checkLEFT, checkDOWN, checkRIGHT);
            break;

        case KEY_RIGHT:
            resetCheck(arrow, checkUP, checkLEFT, checkDOWN, checkRIGHT);
            if(direction(checkUP, checkLEFT, checkDOWN, checkRIGHT) == 4){
                (*move).position.x += 1;
                if( (*move).position.x > maxc-1 )// Right limit -30
                    (*move).position.x -= 1;
            }
            maxCheck(arrow, checkUP, checkLEFT, checkDOWN, checkRIGHT);
            break;
        case 'b':
            checkDirection = direction(checkUP, checkLEFT, checkDOWN, checkRIGHT);
            tankToBullet(*move, position_Bullet);
            return checkDirection;
        default:
            return checkDirection;
    }
    refresh();
}

int main() {
    int dir = 0;
    setlocale(LC_ALL,"");
    struct Tanks tank1 = {7,7};
    struct Bullets bullet = {0,0};

    iniciar_Curses();
    getmaxyx(stdscr,row,col);

    while(teclas(&tank1, &bullet) != KEY_BREAK){
        clear();
        printMap();
        printBullet(tank1,&bullet, bullet, dir);
        printTank(tank1);
        dir = teclas(&tank1, &bullet);

        DEBUG(row-10,0,"dir is %i", dir);
        usleep(20000);
    }
    finalizar_Curses();
    return EXIT_SUCCESS;
}

