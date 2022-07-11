#pragma once
#include "Board.h"
#include "Tile.h"
class MyBoard :
    public Board
{
    void updateField(int x, int y, Tile tile);
public:
   // MyBoard(int size);
    //MyBoard();
};

