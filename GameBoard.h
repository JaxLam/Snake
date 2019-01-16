#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <list>

class GameBoard {
  public:
    GameBoard();
    GameBoard(int newHeight, int newWidth);

  private:
    int height;
    int width;
    //std::list<std::string> units;
    void side();
};

#endif