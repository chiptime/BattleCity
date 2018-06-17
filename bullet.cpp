//
// Created by bruno on 15/06/18.
//
#include "bullet.h"


void tankToBullet(struct Tanks atank, struct Bullets *bullet) {
    bullet->position.x = atank.position.x;
    bullet->position.y = atank.position.y;
}
void printBullet(struct Tanks tbullet, struct Bullets *position_Bullet, struct Bullets position, int checkDirection) {

    mvprintw((int) position.position.y, (int) position.position.x, "*");
    DEBUG(40, 70, "La direccion a la que mira es %i", checkDirection);

    if (position.position.x < 40 && position.position.x > 1 && position.position.y > 1 && position.position.y < 25) {
        if (checkDirection == 1)
            position_Bullet->position.y--;

        if (checkDirection == 2)
            position_Bullet->position.x--;

        if (checkDirection == 3)
            position_Bullet->position.y++;

        if (checkDirection == 4)
            position_Bullet->position.x++;
    } else {
        mvprintw((int) position_Bullet->position.y, (int) position_Bullet->position.x, " ");
    }
    DEBUG(20, 60, "La posicion Y = %lf,La posicion X = %lf", position_Bullet->position.y, position_Bullet->position.x);
    refresh();
}
























/*


void printBullet(struct Tanks tbullet, struct Bullets *position){

    struct Bullets position_Bullet;

    mvprintw(position_Bullet.position.y,position_Bullet.position.y, "*");
    DEBUG(40,70, "La direccion a la que mira es %i",checkDirection);

    if(position_Bullet.position.x<40 && position_Bullet.position.x>1 && position_Bullet.position.y>1 && position_Bullet.position.y<25){
        if(checkDirection == 1)
            position->position.x--;

        if(checkDirection == 2)
            position->position.y--;

        if(checkDirection == 3)
            position->position.y++;

        if(checkDirection == 4)
            position->position.x++;
    }
    else{
        mvprintw(position_Bullet.position.y,position_Bullet.position.x, " ");
    }
    DEBUG(20,60,"La posicion Y = %lf,La posicion X = %lf",position_Bullet.position.y,position_Bullet.position.x);
    refresh();
}
 */
