#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <list>

struct Coordinate {
  int x;
  int y;
  int dir;
};

class GameBoard {
  public:
    explicit GameBoard();
    explicit GameBoard(int newHeight, int newWidth);
    ~GameBoard();
    void showBoard() const;
    bool move();
    bool autoMove();

  private:
    int height;
    int width;
    std::list<Coordinate> snake;
    int snakeLength;
    Coordinate food;
    bool** board;

    Coordinate generateCoordinate();

    void showSnake() const;
    void showHead() const;
    void showBarLine() const;

    bool checkAndMove(Coordinate newHead);
    bool eatFood(Coordinate newHead);
    void justMove(Coordinate newHead);

    void assignBoard();
    void deleteBoard();
};

#endif