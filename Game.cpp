#include "Game.h"
#include <iostream>
#include <string>
#include <windows.h>
#include "Menu.h"

Game::Game(int size) {
    this->size = size;
    turnCounter = 0;
    myBoard = MyBoard(size);
    realBoard = RealBoard(size);

}
void Game::validateMove() {
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

        if (realBoard.ary[x][y].checkIsMine() == true) {
            
            Menu m;
            int temp = 0;
            while (temp == 0) {
                std::string input;
                std::cout << "BOOOOOOOM!\n";
                std::cout << "YOU LOSE!\n";
                std::cout << "1. Back to MENU\n";
                std::cout << "2. Exit\n";

                std::cin >> input;
                if (input == "1")
                    m.start();
                else if (input == "2")
                    exit(0);
                else {
                    std::cout << "Incorect value, type 1 or 2";
                    Sleep(2000);
                    system("cls");
                    temp = 0;
                }

            }
            exit(0);
        }

        if (myBoard.ary[x][y].isClicked == true) {
            std::cout << "This tile was already checked. Try another one.";
            continue;
        }
        else {
            validCoordinate = true;
            if (turnCounter > 1)
                makeMove(x, y);
            else if (turnCounter == 1)
            {
                realBoard.randomMineGenerator(x, y);
                realBoard.checkAllTiles();
                makeMove(x,y);
            }
                
                
        }

    }
}

void Game::makeMove(int x, int y) {
    myBoard.ary[x][y] = realBoard.ary[x][y];

    if (myBoard.ary[x][y].numOfMinesAround == 0) {
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if ((x + i >= size) || (y + j >= size) || (x + i < 0) ||
                    (y + j < 0) || (myBoard.ary[x + i][y + j].isClicked == true))
                    continue;
                else
                    makeMove(x + i, y + j);

            }
        }
    }
}

void Game::playGame() {
    
    while (1) {
        turnCounter++;
        system("cls");
        std::cout << "Turn: " << turnCounter << "\n\n";
        realBoard.printBoard();
        std::cout << "\n";
        myBoard.printBoard();
        std::cout << "\n";
        validateMove();
        checkIsWin(size);
    }

}
void Game::checkIsWin(int size) {

    int suma = 0;

    for (int p = 0; p < size; p++) {
        for (int x = 0; x < size; x++) {

            if (myBoard.ary[p][x].isClicked == true || realBoard.ary[p][x].checkIsMine() == true) {
                suma++;
            }
        }
    }
    if (suma == size * size) {
        Menu m;
        int temp = 0;
        while (temp == 0) {
            std::string input;
            std::cout << "Congratulations! You won!\n\n";
            std::cout << "What do you want to do now?\n";
            std::cout << "1. Back to MENU\n";
            std::cout << "2. Exit\n";

            std::cin >> input;
            if (input == "1")
                m.start();
            else if (input == "2")
                exit(0);
            else {
                std::cout << "Incorrect value, type 1 or 2";
                Sleep(2000);
                system("cls");
                temp = 0;
            }

        }

    }
}