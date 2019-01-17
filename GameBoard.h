#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <list>

struct Coordinate {
  int x;
  int y;
};

class GameBoard {
  public:
    GameBoard();
    GameBoard(int newHeight, int newWidth);
    void showBoard() const;
    void move();

  private:
    int height;
    int width;
    Coordinate snakeHead;
    std::list<int> snakeDir;
    
};

#endif