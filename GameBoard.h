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

  private:
    int height;
    int width;
    std::list<Coordinate> snake;
    int snakeLength;
    bool** positions;
    Coordinate food;
    Coordinate generateCoordinate();
    bool eatFood(int x, int y);
    void showSnake() const;
    void showHead() const;
    bool checkCollision(int x, int y);
    void showBarLine() const;
    void assignPositions();
    void changePositions(int x, int y);
    void deletePositions();
};

#endif