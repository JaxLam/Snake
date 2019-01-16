#include "GameBoard.h"

#include <iostream>

const int MAX_HEIGHT = 25;
const int MAX_WIDTH = 50;
const int MIN_HEIGHT = 5;
const int MIN_Width = 5;

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

void GameBoard::showBoard() const {
    std::cout << " ";
    for (int i = 0; i < width; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
    for (int i = 0;i < height; i++) {
        std::cout << "|";
        for (int j = 0;j < width; j++) {
                std::cout << " ";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << " ";
    for (int i = 0; i < width; i++) {
        std::cout << "-";
    }
}