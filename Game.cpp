#include "Game.h"


Game::Game(int size)
{
	this->size = size;
	turnCounter = 0;
	myBoard = MyBoard();
	realBoard = RealBoard();


}
