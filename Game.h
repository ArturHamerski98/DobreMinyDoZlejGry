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
	Game(int size);




};

