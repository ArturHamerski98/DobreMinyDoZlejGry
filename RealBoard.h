#pragma once
#include "Board.h"
class RealBoard :
    public Board
{

public:
   void randomMineGenerator(int x, int y);
   RealBoard(int size);
   void checkAllTiles();
   RealBoard();

};

