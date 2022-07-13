#include <iostream>
#include "Game.h"
#include "Menu.h"

int main() {
    system("Color 30");
    Menu s;
    Game game(s.start());
    game.playGame();
    return 0;
}
