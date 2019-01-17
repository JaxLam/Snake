#include "system.h"
#include <iostream>

#ifdef _WIN32
#include <conio.h>
int arrowKeys() {
    return _getch();    
}

void clearScreen() {
    system("cls");
}

#else
#include <curses.h>
int arrowKeys() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    int key;
    key = getch();
    endwin();
    return key;
}
void clearScreen() {
    system("clear");
}
#endif