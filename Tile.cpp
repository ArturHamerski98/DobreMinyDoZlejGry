#include "Tile.h"

Tile::Tile(){
	isClicked = false;
	isMine = false;
	numOfMinesAround = 0;
}

int Tile::checkNumOfMinesAround(){
	return this->numOfMinesAround;
}

bool Tile::checkIsClicked(){
	return this->isClicked;
}

void Tile::setNumOfMinesAround(){
	this->numOfMinesAround = numOfMinesAround + 1;
}

void Tile::setClicked(){
	this->isClicked = true;
}

bool Tile::checkIsMine(){
	return this->isMine;
}

void Tile::setMine(){
	this->isMine = true;
}
