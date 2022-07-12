#pragma once
#include "Tile.h"

class Board
{
protected:
	int size;
	
public:
	Tile** ary;
	
	void printBoard();
};

