#include "GameBoard.h"
#include "system.h"
#include <iostream>
#include <iterator>
#include <vector>
#include <ctime>

const int MAX_HEIGHT = 25;
const int MAX_WIDTH = 50;
const int MIN_HEIGHT = 5;
const int MIN_WIDTH = 5;

GameBoard::GameBoard() {
    srand(time(NULL));

    height = MAX_HEIGHT;
    width = MAX_WIDTH;
    assignBoard();

    food = generateCoordinate();

    Coordinate snakeHead = generateCoordinate();
    snake.push_back(snakeHead);
    snakeLength = snake.size();
    board[snakeHead.y][snakeHead.x] = true;
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
    assignBoard();

    food = generateCoordinate();

    Coordinate snakeHead = generateCoordinate();
    snake.push_back(snakeHead);
    snakeLength = snake.size();
    board[snakeHead.y][snakeHead.x] = true;
}

GameBoard::~GameBoard() {
    deleteBoard();
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
            Coordinate newHead = snake.front();
            newHead.y--;
            return !checkAndMove(newHead);
        }
        return true;
        break;
    case KEY_DOWN:
        if (snakeLength == 1 || std::next(it)->dir != 1)
        {
            snake.front().dir = 2;
            Coordinate newHead = snake.front();
            newHead.y++;
            return !checkAndMove(newHead);
        }
        return true;
        break;
    case KEY_LEFT:
        if (snakeLength == 1 || std::next(it)->dir != 4)
        {
            snake.front().dir = 3;
            Coordinate newHead = snake.front();
            newHead.x--;
            return !checkAndMove(newHead);        
        }
        return true;
        break;
    case KEY_RIGHT:
        if (snakeLength == 1 || std::next(it)->dir != 3)
        {
            snake.front().dir = 4;
            Coordinate newHead = snake.front();
            newHead.x++;
            return !checkAndMove(newHead);       
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
            if (!board[i][j]) {
                temp.push_back({j, i, 1});
            }
        }
    }

    int num = temp.size();
    int randomIndex = rand() % num;
    return temp[randomIndex];
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
            else if (board[i][j]) {
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

bool GameBoard::checkAndMove(Coordinate newHead) {
    bool collide = true;
    if (newHead.x == -1 || newHead.x == width ||
     newHead.y == -1 || newHead.y == height 
     || ((newHead.x != snake.back().x || 
     newHead.y != snake.back().y) && 
     board[newHead.y][newHead.x])) {

        return collide;
    }
    else{
        if (!eatFood(newHead)) {
            changeBoard(newHead);
        }
        return !collide;
    }
}

bool GameBoard::eatFood(Coordinate newHead) {
    if (food.y == newHead.y && food.x == newHead.x) {
        food.dir = snake.front().dir;
        snake.insert(snake.begin(), food);
        snakeLength = snake.size();
        board[food.y][food.x] = true;
        food = generateCoordinate();
        return true;
    }
    return false;
}

void GameBoard::changeBoard(Coordinate newHead) {
    board[snake.back().y][snake.back().x] = false;
    if (snakeLength != 1)
    {
        for (std::list<Coordinate>::iterator it = prev(snake.end()); it != snake.begin(); --it)
        {
            *it = *prev(it);
        }
    }
    snake.front() = newHead;
    board[snake.front().y][snake.front().x] = true;
}

void GameBoard::assignBoard() {
    board = new bool*[height];
    for (int i = 0; i < height; i++) {
        board[i] = new bool[width];
        for (int j = 0;j < width;j++) {
            board[i][j] = false;
        }
    }
}

void GameBoard::deleteBoard() {
    for (int i = 0; i < height;i++) {
        delete [] board[i];
    }
    delete [] board;
}