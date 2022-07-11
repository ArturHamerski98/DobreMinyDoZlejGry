#include <iostream>
#include "Game.h"

int main() {
    
    int rozmiar;
    std::cout << "Choose lvl;";
    std::cin >> rozmiar;
    Game game(rozmiar);
    std::cout<<game.myBoard.ary[3][8].numOfMinesAround;
    std::cout << "siemano";

    return 0;
}