#include "RealBoard.h"

void RealBoard::randomMineGenerator(int x, int y)
{
	int iloscMinNaMapie;
	int iloscRozdanych = 0;

	if (size == [9]) {
		iloscMinNaMapie = 10;
	}
	if (size == [16]) {
		iloscMinNaMapie = 40;
	}
	if (size == [24]) {
		iloscMinNaMapie = 99;

	}
	srand(time(NULL));
	
	while (iloscRozdanych < iloscMinNaMapie) {
		
		int a = rand() % 10;
		int b = rand() % 10;

		if (a == x && b == y) {
			continue;
		}
		else if (ary[a][b].isMine == true) {
			continue;
		}
		else if (ary[a][b].isMine == false){
			ary[a][b].isMine = true;
			iloscRozdanych++;
		}
	}
}
