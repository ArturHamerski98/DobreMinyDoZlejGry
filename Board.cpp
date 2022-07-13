#include "Board.h"
#include <iostream>


void Board::printBoard() {

    for (int u = 0; u < size + 1; u++) {
        for (int v = 0; v < size + 1; v++)
            if (v == 0) {
                if (u == 0)
                    std::cout << "   ";
                else {
                    std::cout << u << " ";
                    if (u < 10)
                        std::cout << " ";
                }
            }
            else if (u == 0) {
                if (v == 0)
                    std::cout << " ";
                std::cout << v << " ";
                if (v < 10)
                    std::cout << " ";
            }
            else if (ary[u - 1][v - 1].checkIsClicked() == false)
                std::cout << "   ";
            else if (ary[u - 1][v - 1].checkIsMine() == true)
                std::cout << "M" << "  ";
            else
                std::cout << ary[u - 1][v - 1].checkNumOfMinesAround() << "  ";
        std::cout << std::endl;
    }
}