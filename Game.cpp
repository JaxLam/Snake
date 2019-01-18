#include "Game.h"

#include <iostream>

#include "GameBoard.h"
#include "system.h"

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