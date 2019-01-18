#include "GameBoard.h"

#include <iostream>
#include <iterator>
#include "system.h"


#ifdef _WIN32
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#else
#define KEY_UP 0403
#define KEY_DOWN 0402
#define KEY_LEFT 0404
#define KEY_RIGHT 0405
#endif
const int snakeLength = 5;

const int MAX_HEIGHT = 25;
const int MAX_WIDTH = 50;
const int MIN_HEIGHT = 5;
const int MIN_WIDTH = 5;

GameBoard::GameBoard() {
    height = MAX_HEIGHT;
    width = MAX_WIDTH;
    Coordinate snakeHead = {25, 10, 4},
               snake2 = {24, 10, 4},
               snake3 = {23, 10, 4},
               snake4 = {22, 10, 4},
               snake5 = {21, 10, 4},
               snake6 = {20, 10, 4};
    snake.push_back(snakeHead);
    snake.push_back(snake2);
    snake.push_back(snake3);
    snake.push_back(snake4);
    snake.push_back(snake5);
    snake.push_back(snake6);

    assignPositions();
    positions[snakeHead.y][snakeHead.x] = true;
    positions[10][24] = true;
    positions[10][23] = true;
    positions[10][22] = true;
    positions[10][21] = true;
    positions[10][20] = true;
}

GameBoard::GameBoard(int newHeight, int newWidth) {
    if ((newHeight > MIN_HEIGHT) && (newWidth > MIN_WIDTH) && 
    (newHeight < MAX_HEIGHT) && (newWidth < MAX_WIDTH)) {
        height = newHeight;
        width = newWidth;
    }
    else {
        height = MAX_WIDTH;
        width = MAX_WIDTH;
    }
    Coordinate snakeHead = {25, 10, 1};
    snake.push_back(snakeHead);
    assignPositions();
    positions[snakeHead.y][snakeHead.x] = true;
}

GameBoard::~GameBoard() {
    deletePositions();
}

void GameBoard::showBoard() const {
    showBarLine();
    showSnake();
    showBarLine();
}

bool GameBoard::move() {
    std::list<Coordinate>::iterator it = snake.begin();
    switch (arrowKeys())
    {
    case KEY_UP:
        if (snakeLength == 1 || std::next(it)->dir != 2)
        {
            snake.front().dir = 1;
            return !checkCollision(0, -1);
        }
        return true;
        break;
    case KEY_DOWN:
        if (snakeLength == 1 || std::next(it)->dir != 1)
        {
            snake.front().dir = 2;
            return !checkCollision(0, 1);
        }
        return true;
        break;
    case KEY_LEFT:
        if (snakeLength == 1 || std::next(it)->dir != 4)
        {
            snake.front().dir = 3;
            return !checkCollision(-1, 0);
        }
        return true;
        break;
    case KEY_RIGHT:
        if (snakeLength == 1 || std::next(it)->dir != 3)
        {
            snake.front().dir = 4;
            return !checkCollision(1, 0);
        }
        return true;
        break;
    default:
        return true;
        break;
    }
    return false;
}

void GameBoard::showSnake() const {
    for (int i = 0;i < height; i++) {
        std::cout << "|";
        for (int j = 0; j < width; j++) {
            if (i==snake.front().y && j == snake.front().x) {
                showHead();
            }
            else if (positions[i][j]) {
                std::cout << "o";
            }
            else{
                std::cout << " ";
            }
        }
        std::cout << "|\n";
    }
}

void GameBoard::showHead() const{
    switch (snake.front().dir)
    {
    case 1:
        std::cout << "⁀";
        break;
    case 2:
        std::cout << "‿";
        break;
    case 3:
        std::cout << "(";
        break;
    case 4:
        std::cout << ")";
        break;
    default:
        std::cout << "⁀";
    }
}

void GameBoard::showBarLine() const {
    std::cout << " ";
    for (int i = 0; i < width; i++) {
        std::cout << "-";
    }
    std::cout << " " << std::endl;
}

void GameBoard::assignPositions() {
    positions = new bool*[height];
    for (int i = 0; i < height; i++) {
        positions[i] = new bool[width];
        for (int j = 0;j < width;j++) {
            positions[i][j] = false;
        }
    }
}

void GameBoard::changePositions(int x, int y) {
    positions[snake.back().y][snake.back().x] = false;
    if (snakeLength != 1) {
        for (std::list<Coordinate>::iterator it = prev(snake.end());it != snake.begin();it--) {
            *it = *std::prev(it);
        }
    }
    snake.front().x += x;
    snake.front().y += y;
    positions[snake.front().y][snake.front().x] = true;
}

void GameBoard::deletePositions() {
    for (int i = 0; i < height;i++) {
        delete [] positions[i];
    }
    delete [] positions;
}

bool GameBoard::checkCollision(int x, int y) {
    bool do_collide = true;
    int temp_x = snake.front().x + x;
    int temp_y = snake.front().y + y;
             std::cout << "temp_x"  << temp_x << "temp_y" << temp_y << "\n" 
         << snake.back().x << snake.back().y << "\n";
    if (temp_x == -1 || temp_x == width ||
     temp_y == -1 || temp_y == height 
     || ((temp_x != snake.back().x || 
     temp_y != snake.back().y) && 
     positions[temp_y][temp_x])) {

        return do_collide;
    }
    else{
        changePositions(x, y);
        return !do_collide;
    }
}