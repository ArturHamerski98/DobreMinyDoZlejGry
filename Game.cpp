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
    std::string a, b;
    bool validCoordinate = false;

    while (validCoordinate == false) {
        std::cout << "Enter x coordinate: ";
        std::getline(std::cin, a);

        int sum = 0;
        for (int i = 0; i < a.size(); i++) {
            if (isdigit(a[i]))sum++;
        }
        if (sum == a.size()) x = std::stoi(a);

        x--;

        while (x > size - 1 || x < 0) {
            std::cout << "Invalid coordinate. Type coordinate again!\n";
            std::cout << "Enter x coordinate: ";
            std::getline(std::cin, a);

            int sum = 0;

            for (int i = 0; i < a.size(); i++)
                if (isdigit(a[i]))sum++;
            if (sum == a.size())
                x = std::stoi(a);

            x--;
        }

        std::cout << "Enter y coordinate: ";
        std::getline(std::cin, b);

        int sum2 = 0;
        for (int i = 0; i < b.size(); i++)
            if (isdigit(b[i]))sum2++;
        if (sum2 == b.size())
            y = std::stoi(b);

        y--;

        while (y > size - 1 || y < 0) {
            std::cout << "Invalid coordinate. Type coordinate again\n";
            std::cout << "Enter y coordinate: ";

            std::getline(std::cin, b);
            int sum2 = 0;

            for (int i = 0; i < b.size(); i++)
                if (isdigit(b[i]))sum2++;
            if (sum2 == b.size())
                y = std::stoi(b);

            y--;
        }

        if (realBoard.ary[x][y].checkIsMine() == true) {

            Menu m;
            int temp = 0;
            while (temp == 0) {
                std::string input;
                system("cls");
                realBoard.printBoard();
                std::cout << "\nBOOOOOOOM!\n";
                std::cout << "YOU LOSE!\n\n";
                std::cout << "1. Back to MENU\n";
                std::cout << "2. Exit\n";

                std::getline(std::cin, input);
                if (input == "1")
                {
                    Game game(m.start());
                    game.playGame();
                }
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
        if (myBoard.ary[x][y].checkIsClicked() == true) {
            std::cout << "This tile was already checked. Try another one.\n";
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
                makeMove(x, y);
            }
        }
    }
}

void Game::makeMove(int x, int y) {
    myBoard.ary[x][y] = realBoard.ary[x][y];

    if (myBoard.ary[x][y].checkNumOfMinesAround() == 0) {
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if ((x + i >= size) || (y + j >= size) || (x + i < 0) ||
                    (y + j < 0) || (myBoard.ary[x + i][y + j].checkIsClicked() == true))
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

            if (myBoard.ary[p][x].checkIsClicked() == true || realBoard.ary[p][x].checkIsMine() == true) {
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
            {
                Game game(m.start());
                game.playGame();
            }
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