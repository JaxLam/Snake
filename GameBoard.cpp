#include "GameBoard.h"
#include "system.h"
#include <iostream>
#include <iterator>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

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

const int MAX_HEIGHT = 25;
const int MAX_WIDTH = 50;
const int MIN_HEIGHT = 5;
const int MIN_WIDTH = 5;

GameBoard::GameBoard() {
    srand(time(NULL));

    height = MAX_HEIGHT;
    width = MAX_WIDTH;
    assignPositions();

    food = generateCoordinate();

    Coordinate snakeHead = generateCoordinate();
    snake.push_back(snakeHead);
    snakeLength = snake.size();
    positions[snakeHead.y][snakeHead.x] = true;
}

GameBoard::GameBoard(int newHeight, int newWidth) {
    srand(time(NULL));

    if ((newHeight > MIN_HEIGHT) && (newWidth > MIN_WIDTH) && 
    (newHeight < MAX_HEIGHT) && (newWidth < MAX_WIDTH)) {
        height = newHeight;
        width = newWidth;
    }
    else {
        height = MAX_WIDTH;
        width = MAX_WIDTH;
    }
    assignPositions();

    food = generateCoordinate();

    Coordinate snakeHead = generateCoordinate();
    snake.push_back(snakeHead);
    snakeLength = snake.size();
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

Coordinate GameBoard::generateCoordinate() {
    std::vector<Coordinate> temp;
    for (int i = 0;i < height;i++) {
        for (int j = 0;j < width;j++) {
            if (!positions[i][j]) {
                temp.push_back({j, i, 1});
            }
        }
    }

    int num = temp.size();
    int randomIndex = rand() % num;
    return temp[randomIndex];
}

bool GameBoard::eatFood(int x, int y) {
    if (food.y == y && food.x == x) {
        food.dir = snake.front().dir;
        snake.insert(snake.begin(), food);
        snakeLength = snake.size();
        positions[food.y][food.x] = true;
        food = generateCoordinate();
        return true;
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
            else if (i == food.y && j == food.x) {
                std::cout << "*";
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
        std::cout << "A";
        break;
    case 2:
        std::cout << "V";
        break;
    case 3:
        std::cout << "(";
        break;
    case 4:
        std::cout << ")";
        break;
    default:
        std::cout << "A";
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
    if (snakeLength != 1)
    {
        for (std::list<Coordinate>::iterator it = prev(snake.end()); it != snake.begin(); --it)
        {
            *it = *prev(it);
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
    if (temp_x == -1 || temp_x == width ||
     temp_y == -1 || temp_y == height 
     || ((temp_x != snake.back().x || 
     temp_y != snake.back().y) && 
     positions[temp_y][temp_x])) {

        return do_collide;
    }
    else{
        if (!eatFood(temp_x, temp_y)) {
            changePositions(x, y);
        }
        return !do_collide;
    }
}