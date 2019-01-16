#include "GameBoard.h"

const int MAX_HEIGHT = 50;
const int MAX_WIDTH = 50;
const int MIN_HEIGHT = 10;
const int MIN_Width = 10;

GameBoard::GameBoard() {
    height = MAX_HEIGHT;
    width = MAX_WIDTH;
}

GameBoard::GameBoard(int newHeight, int newWidth) {
    if ((newHeight > MIN_HEIGHT) && (newWidth > MIN_Width)) {
        height = newHeight;
        width = newWidth;
    }
    else {
        height = MIN_HEIGHT;
        width = MIN_Width;
    }
}