#include "Board.h"
#include <iostream>
#include <io.h>
#include <conio.h>
#include <fcntl.h>

void Board::printBoard()
{
    _setmode(_fileno(stdout), _O_WTEXT);
    for (int u = 0; u < size+1; u++) {
        for (int v = 0; v < size + 1; v++)
            if (v == 0)
            {
                if (u == 0)
                    std::wcout << "   ";
                else {
                    std::wcout << u << " ";
                    if (u < 10)
                        std::wcout << " ";
                }

            }
            else if (u == 0) {
                if (v == 0)
                    std::wcout << " ";
                std::wcout << v << " ";
                if (v < 10)
                    std::wcout << " ";
            }
            else if (ary[u - 1][v - 1].isClicked == false)
                std::wcout << "   ";
            else if (ary[u - 1][v - 1].isMine == true)
                std::wcout << L'\u00E8' << "  ";
            else
                std::wcout << ary[u-1][v-1].numOfMinesAround << "  ";
        std::wcout << std::endl;
    }
}
