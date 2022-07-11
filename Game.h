#pragma once
#include "MyBoard.h"
#include "RealBoard.h"
#include "Board.h"
class Game
{
public:
	int size;
	int turnCounter;
	MyBoard myBoard;
	RealBoard realBoard;

public:
	void CheckIsWin();
	void makeAMove();
	bool isOccupied(int x, int y);
	Game(int size);




};

