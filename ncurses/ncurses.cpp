//
// Created by bruno on 14/06/18.
//

#include "ncurses.h"

void iniciar_Curses(){
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    halfdelay(1);
    //cbreak();
    nodelay(stdscr,true);
    noecho();

}

void finalizar_Curses(){
    curs_set(1);
    endwin();
}
