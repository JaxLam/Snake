#include "GameBoard.h"

#include <iostream>
#include "system.h"

const int MAX_HEIGHT = 25;
const int MAX_WIDTH = 50;
const int MIN_HEIGHT = 5;
const int MIN_Width = 5;

GameBoard::GameBoard() {
    height = MAX_HEIGHT;
    width = MAX_WIDTH;
    snakeHead.x = 25;
    snakeHead.y = 10;
    snakeDir.front() = 1;
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
    snakeHead.x = 25;
    snakeHead.y = 10;
    snakeDir.front() = 1;
}

void GameBoard::showBoard() const {
    std::cout << " ";
    for (int i = 0; i < width; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
    for (int i = 0;i < height; i++) {
        std::cout << "|";
        if (i == snakeHead.y) {
            for (int j = 0; j < width; j++) {
                if (j == snakeHead.x) {
                    switch(snakeDir.front()) {
                        case 1:
                            std::cout << "A";
                            break;
                        case 2:
                            std::cout << "V";
                            break;
                        case 3:
                            std::cout << "<";
                            break;
                        case 4:
                            std::cout << ">";
                            break;
                        default:
                            std::cout << "A";
                    }
                }
                else {
                    std::cout << " ";
                }
            }
        }
        else {
            for (int j = 0;j < width; j++) {
                    std::cout << " ";
            }
        }
        std::cout << "|" << std::endl;
    }
    std::cout << " ";
    for (int i = 0; i < width; i++) {
        std::cout << "-";
    }
}

void GameBoard::move() {
        switch(arrowKeys()) {
        case 72:
            snakeHead.y--;
            snakeDir.front() = 1;
            break;
        case 80:
            snakeHead.y++;
            snakeDir.front() = 2;
            break;
        case 75:
            snakeHead.x--;
            snakeDir.front() = 3;
            break;
        case 77:
            snakeHead.x++;
            snakeDir.front() = 4;
            break;
        }
    clear();
    showBoard();
}