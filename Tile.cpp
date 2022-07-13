#include "Tile.h"

Tile::Tile()
{
	isClicked = false;
	isMine = false;
	numOfMinesAround = 0;
}

bool Tile::checkIsMine()
{
	return this->isMine;
}

void Tile::setMine()
{
	this->isMine = true;
}
