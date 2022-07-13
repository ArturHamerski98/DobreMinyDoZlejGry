#pragma once
class Tile
{
private:
	bool isMine;
	bool isClicked;
	int numOfMinesAround;

public:
	Tile();
	int checkNumOfMinesAround();
	void setNumOfMinesAround();
	bool checkIsClicked();
	void setClicked();
	bool checkIsMine();
	void setMine();

};

