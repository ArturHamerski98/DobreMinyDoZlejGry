#include "Game.h"
#include <iostream>

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

    if (myBoard.ary[x][y].numOfMinesAround == 0) {
        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                if ((x + i >= size) || (y + j >= size) || (x + i < 0)
                    || (y + j < 0) || (myBoard.ary[x + i][y + j].isClicked == true))
                    continue;
                else
                    makeMove(x + i, y + j);

            }
        }
    }
}

void Game::playGame()
{
    int i = 0;
    while (1) {
        if (i == 0)
        {
            realBoard.randomMineGenerator(3, 4);
            realBoard.checkAllTiles();
        }
        system("cls");
        realBoard.printBoard();
        std::cout << "\n";
        myBoard.printBoard();
        std::cout << "\n";
        validateMove();
       
        i++;
    }

}
