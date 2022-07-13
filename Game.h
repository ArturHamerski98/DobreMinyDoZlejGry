#pragma once
#include "MyBoard.h"
#include "RealBoard.h"
#include "Board.h"
#include "Tile.h"
#include <string>

class Game
{
private:
    std::string inputRozmiar{};
    int choice{};
    int size;
    int turnCounter;
    void CheckIsWin(int size);
public:
    MyBoard myBoard;
    RealBoard realBoard;
    Game(int size);
    void validateMove();
    void makeMove(int x, int y);
    void playGame();
    bool checkChoiceValue();
    int checkChoice();
    bool checkNumbers(char c);


};