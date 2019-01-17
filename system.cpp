#include "system.h"
#include <iostream>

#ifdef _WIN32
#include <conio.h>
int arrowKeys() {
    return _getch();    
}

void clear() {
    system("cls");
}

#else
#include <ncurses.h>
int arrowKeys() {
    return getch();
}
void clear() {
    system("clear");
}
#endif