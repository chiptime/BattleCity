//
// Created by bruno on 14/06/18.
//

#include "tank.h"
#include <ncurses.h>


void resetCheck(int key, int &UP, int &LEFT, int &DOWN, int &RIGHT){
    if(key == KEY_UP){
        RIGHT = 0;
        DOWN  = 0;
        LEFT  = 0;
    }
    else{
        if(key == KEY_LEFT){
            RIGHT = 0;
            DOWN  = 0;
            UP    = 0;
        }
        else{
            if(key == KEY_DOWN){
                RIGHT = 0;
                LEFT  = 0;
                UP    = 0;
            }
            else{
                if(key == KEY_RIGHT){
                    DOWN  = 0;
                    LEFT  = 0;
                    UP    = 0;
                }
            }
        }
    }
}
void printTank(struct Tanks tank) {
    mvprintw((int)tank.position.y,(int)tank.position.x,"H");
    refresh();
}
void maxCheck(int key, int &UP, int &LEFT, int &DOWN, int &RIGHT){
    switch (key){
        case KEY_UP:
            UP += 1;
            if(UP > 1)
                UP -= 1;
            break;
        case KEY_LEFT:
            LEFT += 1;
            if(LEFT > 1)
                LEFT -= 1;
            break;
        case KEY_DOWN:
            DOWN -= 1;
            if(DOWN < -1)
                DOWN += 1;
            break;
        case KEY_RIGHT:
            RIGHT -= 1;
            if(RIGHT < -1)
                RIGHT += 1;
            break;
    }

}
int direction(int UP, int LEFT, int DOWN, int RIGHT){
    if(UP    ==  1)
        return 1;

    if(LEFT  ==  1)
        return 2;

    if(DOWN  == -1)
        return 3;

    if(RIGHT == -1)
        return 4;
}
