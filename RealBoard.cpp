#include "RealBoard.h"
#include <time.h>
#include <stdlib.h>
#include <ctime>

void RealBoard::randomMineGenerator(int x, int y)
{
	int iloscMinNaMapie;
	int iloscRozdanych = 0;

	if (size == 9) {
		iloscMinNaMapie = 10;
	}
	if (size == 16) {
		iloscMinNaMapie = 40;
	}
	if (size == 24) {
		iloscMinNaMapie = 99;

	}
	srand(time(NULL));


	while (iloscRozdanych < iloscMinNaMapie) {

		int a = rand() % 9;
		int b = rand() % 9;


		if (a == x && b == y) {
			continue;
		}
		else if (ary[a][b].isMine == true) {
			continue;
		}

		else if (ary[a][b].isMine == false) {
			ary[a][b].isClicked = true;
=======
		else if (ary[a][b].isMine == false){

			ary[a][b].isMine = true;
			iloscRozdanych++;
		}
	}
}


RealBoard::RealBoard(int size)
{
    this->size = size;
    ary = new Tile * [size];
    for (int i = 0; i < size; i++) {
        ary[i] = new Tile[size];

    }
}

RealBoard::RealBoard()
{
    size = 10;
    ary = new Tile * [size];
    for (int i = 0; i < size; i++) {
        ary[i] = new Tile[size];

    }
}
=======

