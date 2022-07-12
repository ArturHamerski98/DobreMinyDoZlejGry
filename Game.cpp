#include "Game.h"
#include <iostream>

Game::Game(int size)
{
    this->size = size;
    turnCounter = 0;
    myBoard = MyBoard(size);
    realBoard = RealBoard(size);


}
void Game::makeAMove()
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
            break;
        }

        if (realBoard.ary[x][y].isClicked == true) {
            std::cout << "This tile was already checked. Try another one.";
            continue;
        }
        else
            validCoordinate = true;

    }
}