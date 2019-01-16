#include "menu.h"

#include <iostream>
#include <string>


void Menu::showMenu() {
    std::string prompt = "Please input the number of your choice:";
    std::string choiceOne = "1. Start";
    std::string choiceTwo = "2. Press any key to quit";
    system("clear");
    opening();
    std::cout << std::endl
            << prompt << std::endl
            << choiceOne << std::endl
            << choiceTwo << std::endl;
}

int Menu::inputNum() {
    char number;
    std::cin >> number;
    switch(number) {   
        case '1':
            return 1;
        default:
            return -1;
    }
}

void Menu::goBack() {

}

void Menu::opening() {
    std::string title = "Welcome to my game, Snake";
    std::string description = "I wrote this game to practice my C++ skill";
    std::string closingStatement = "Enjoy!";
    std::string asciiLineOne =   "      _____                    _";
    std::string asciiLineTwo =   "     / ____|                  | |";
    std::string asciiLineThree = "     | (___    _ __     __ _  | | __   ___";
    std::string asciiLineFour =  "      \\___ \\  | '_ \\   / _` | | |/ /  / _ \\";
    std::string asciiLineFive =  "     ____)| | | | | | (_| | | | <  |  |__/";
    std::string asciiLineSix =   "    |_______/ |_| |_|  \\__,_| |_|\\_\\  \\___|";
    std::cout << title << std::endl
            << description <<std::endl
            << closingStatement << std::endl
            << asciiLineOne << std::endl
            << asciiLineTwo << std::endl
            << asciiLineThree << std::endl
            << asciiLineFour << std::endl
            << asciiLineFive << std::endl
            << asciiLineSix << std::endl;
}