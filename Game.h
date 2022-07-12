#pragma once
#include "MyBoard.h"
#include "RealBoard.h"
#include "Board.h"
class Game
{
private:
	int size;
	int turnCounter;
	void CheckIsWin();
public:	
	MyBoard myBoard;
	RealBoard realBoard;
	Game(int size);
	void makeAMove();

};

