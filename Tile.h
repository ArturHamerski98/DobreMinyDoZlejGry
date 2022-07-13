#pragma once
class Tile
{
private:
	bool isMine;

public:
	bool isClicked;
	int numOfMinesAround;
	Tile();
	bool checkIsMine();
	void setMine();
	

};

