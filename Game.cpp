#include "Game.h"
#include "GameBoard.h"
#include "system.h"

void Game::startGame() {
    GameBoard gameBoard;

    clear();
    gameBoard.showBoard();
    while(true) {
        gameBoard.move();
    }
}