#include "Board.h"
#include <iostream>
void Board::printBoard()
{
    for (int u = 0; u < size+1; u++) {
        for (int v = 0; v < size + 1; v++)
            if (v == 0)
            {
                if (u == 0)
                    std::cout << "  ";
                else
                    std::cout << u << " ";

            }
            else if (u == 0)
                std::cout << v << " ";
            else if(ary[u-1][v-1].isClicked==false)
                std::cout <<"  ";
            else if(ary[u-1][v-1].isMine == true)
                std::cout << "M" << " ";
            else
                std::cout << ary[u-1][v-1].numOfMinesAround << " ";
        std::cout << std::endl;
    }
}
