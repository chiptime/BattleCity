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
//DEBUGING
#ifndef NODEBUG
#define DEBUG(...) mvprintw(__VA_ARGS__)
#else
#define DEBUG(...)
#endif
/////////////////
int row,col;
/////////////////


void tankToBullet(struct Tanks atank, struct Bullets *bullet){
    bullet->position.x = atank.position.x;
    bullet->position.y = atank.position.y;
}
/*
void functionBullet(struct Tanks *tank){
    Bullets *position = NULL;
    *position = tankToBullet(*tank);
}*/
void printBullet(struct Tanks tbullet, struct Bullets *position_Bullet, struct Bullets position, int checkDirection){


    mvprintw((int)position.position.y,(int)position.position.x, "*");
    DEBUG(40,70, "La direccion a la que mira es %i",checkDirection);

    if( position.position.x<40 && position.position.x>1 && position.position.y>1 && position.position.y<25){
        if(checkDirection == 1)
            position_Bullet->position.x--;

        if(checkDirection == 2)
            position_Bullet->position.y--;

        if(checkDirection == 3)
            position_Bullet->position.y++;

        if(checkDirection == 4)
            position_Bullet->position.x++;
    }
    else{
        mvprintw((int)position_Bullet->position.y,(int)position_Bullet->position.x, " ");
    }
    DEBUG(20,60,"La posicion Y = %lf,La posicion X = %lf",position_Bullet->position.y,position_Bullet->position.x);
    refresh();
}
////////////////////////////////////////////////////////////////////////////////////////////
int teclas(struct Tanks *move, Bullets *position_Bullet){
    int checkDirection;
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
            //functionBullet(move);
            //*positionInitial = positionTank(*move);
        default:
            return arrow;
    }
    refresh();
    return arrow;
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
        printTank(tank1);
        printBullet(tank1,&bullet, bullet, dir);
        dir = teclas(&tank1, &bullet);
        usleep(20000);
    }
    finalizar_Curses();
    return EXIT_SUCCESS;
}

