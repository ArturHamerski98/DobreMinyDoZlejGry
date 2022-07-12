#include <iostream>
#include "Game.h"

#include "Menu.h"

int main() {

    Menu s;
    
    Game game(s.start());
   
    game.playGame();
    return 0;
}
