//
// Created by bruno on 15/06/18.
//
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