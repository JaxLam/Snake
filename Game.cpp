#include "Game.h"
#include "GameBoard.h"
#include "system.h"
#include <iostream>

void Game::startGame() {
    GameBoard gameBoard;

    while(true) {
        clearScreen();
        gameBoard.showBoard();
        if(!gameBoard.move()) {
            std::cout << "Game Over!\n";
            break;
        }
    }
}