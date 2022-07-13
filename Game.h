#pragma once
#include "MyBoard.h"
#include "RealBoard.h"
#include "Board.h"
class Game
{
private:
    int size;
    int turnCounter;
    void checkIsWin(int size);
    MyBoard myBoard;
    RealBoard realBoard;
    void validateMove();
    void makeMove(int x, int y);

public:
    Game(int size);
    void playGame();
 
};