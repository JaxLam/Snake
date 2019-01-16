#ifndef GAMEBOARD_H
#define GAMEBOARD_H

class GameBoard {
  public:
    GameBoard();
    GameBoard(int newHeight, int newWidth);
    void showBoard() const;

  private:
    int height;
    int width;
    void side();
};

#endif