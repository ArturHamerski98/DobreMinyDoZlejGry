#include "Game.h"
#include <iostream>
#include "Menu.h"

Game::Game(int size)
{
    this->size = size;
    turnCounter = 0;
    myBoard = MyBoard(size);
    realBoard = RealBoard(size);


}
void Game::validateMove()
{
    int x{}, y{};
    bool validCoordinate = false;

    while (validCoordinate == false) {
        std::cout << "Enter x coordinate: ";
        std::cin >> x;
        x--;

        while (x > size || x < 0) {
            std::cout << "Invalid coordinate. Type coordinate again!\n";
            std::cout << "Enter x coordinate: ";
            std::cin >> x;
            x--;
        }

        std::cout << "Enter y coordinate: ";
        std::cin >> y;
        y--;

        while (y > size || y < 0) {
            std::cout << "Invalid coordinate. Type coordinate again\n";
            std::cout << "Enter y coordinate: ";
            std::cin >> y;
            y--;
        }

        if (realBoard.ary[x][y].isMine == true) {
            std::cout << "BOOOOOOOM!\n";
            std::cout << "YOU LOSE!\n";
            exit(0);
        }

        if (myBoard.ary[x][y].isClicked == true) {
            std::cout << "This tile was already checked. Try another one.";
            continue;
        }
        else {
            validCoordinate = true;
            makeMove(x, y);
        }
    }
}

void Game::makeMove(int x, int y)
{
    myBoard.ary[x][y] = realBoard.ary[x][y];

}

void Game::playGame()
{
    int i = 0;
    while (1) {
        realBoard.printBoard();
        std::cout << "\n ";
        myBoard.printBoard();
        std::cout << "\n";
        validateMove();
        if (i == 0)
        {
            realBoard.randomMineGenerator(3, 4);
            realBoard.checkAllTiles();
        }
        i++;

        CheckIsWin(size);
    }

}

void Game::CheckIsWin(int size) {

    int suma = 0;

    for (int p = 0; p < size; p++) {
        for (int x = 0; x < size; x++) {

            if (myBoard.ary[p][x].isClicked == true || realBoard.ary[p][x].isMine == true) {
                suma++;
            }
        }
    }
    if (suma == size * size) {
        std::cout << "Congratulations! You won!\n\n";
        std::cout << "What do you want to do now?\n";
        std::cout << "1. Back to MENU\n"; 
        std::cout << "2. Exit\n";

        Menu s;
        switch (checkChoice()) {
        case 1: s.start(); 
        case 2: exit(0);
        }
    }
}
bool Menu::checkNumbers(char c) {
    return c >= '0' && c <= '9';
}

bool Game::checkChoiceValue() {
    if (choice > 2 || choice < 1) {
        std::cout << "The entered value should be in range 1-2, try again: ";
    }

    return (choice <= 2 && choice >= 1);
}

int Game::checkChoice() {
    do {
        std::cin >> choice;
        for (int i = 0; !inputRozmiar.empty() && (i <= inputRozmiar.length() - 1); i++) {
            if (checkNumbers(inputRozmiar[i])) {
                continue;
            }
            else {
                std::cout << "\nThe entered value is incorrect." << std::endl;
                inputRozmiar.clear();
                break;
            }
        }

        if (!inputRozmiar.empty()) {
            choice = std::stoi(inputRozmiar);
            inputRozmiar.clear();
        }
    } while (!checkChoiceValue());

    return choice;
}

