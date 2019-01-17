#include "Game.h"
#include "GameBoard.h"
#include "system.h"

void Game::startGame() {
    GameBoard gameBoard;

    while(true) {
        clearScreen();
        gameBoard.showBoard();
        gameBoard.move();
    }
}