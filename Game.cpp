#include "Game.h"
#include "GameBoard.h"

void Game::startGame() {
    GameBoard gameBoard;

    system("cls");
    gameBoard.showBoard();
    while(true) {
        gameBoard.move();
    }
}