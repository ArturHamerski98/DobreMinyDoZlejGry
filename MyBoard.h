#pragma once
#include "Board.h"
#include "Tile.h"
class MyBoard :
    public Board
{ 
public:
    void updateField(int x, int y, Tile tile);
    MyBoard(int size);
    MyBoard();
};

