#include "MyBoard.h"

MyBoard::MyBoard(int size)
{
    this->size = size;
    ary = new Tile * [size];
    for (int i = 0; i < size; i++) {
        ary[i] = new Tile[size];
    }
}

MyBoard::MyBoard()
{
    size = 10;
    ary = new Tile * [size];
    for (int i = 0; i < size; i++) {
        ary[i] = new Tile[size];
    }
}
