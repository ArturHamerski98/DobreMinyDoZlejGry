#include <iostream>
#include "Game.h"

int main() {

    int rozmiar;
    std::cout << "Choose lvl;";
    std::cin >> rozmiar;
    Game game(rozmiar);
    //game.realBoard.ary[5][5].isClicked = true;
    //game.realBoard.ary[5][5].isMine = true;
    game.realBoard.randomMineGenerator(3, 4);
    //game.realBoard.printBoard();
    game.realBoard.checkAllTiles();
    std::cout << "\n\n";
    game.myBoard.printBoard();
    std::cout << "\n";
    game.realBoard.printBoard();
    std::cout << "\n";
    game.makeAMove();
    return 0;
}