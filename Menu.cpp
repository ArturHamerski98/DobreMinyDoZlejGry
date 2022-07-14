#include "Menu.h"
#include <iostream>
#include <string>


bool Menu::checkNumbers(char c) {
    return c >= '0' && c <= '9';
}

int Menu::checkNumber() {
    bool isCorrect = false;

    do {
        std::getline(std::cin, inputNumber);

        if (inputNumber != "1" && inputNumber != "2" && inputNumber != "3" && inputNumber != "exit") {
            std::cout << "\nThe entered value is incorrect." << std::endl;
            std::cout << "The entered value should be in range 1-3, try again: ";
        }
        else
            isCorrect = true;

        if (inputNumber == "exit") {
            std::cout << "See you next time!\n\n";
            exit(0);
        }
       
    } while (isCorrect == false);

    return  number = std::stoi(inputNumber);
}

int Menu::displayMenu() {
    system("cls");
    std::cout << "|---------------------------------------------|" << std::endl;
    std::cout << "|                                             |" << std::endl;
    std::cout << "|        Welcome in the MINESWEEPER!          |" << std::endl;
    std::cout << "|                                             |" << std::endl;
    std::cout << "|---------------------------------------------|" << std::endl;

    std::cout << "Choose level\n";
    std::cout << "1. Begginer\n";
    std::cout << "2. Intermediate\n";
    std::cout << "3. Advanced\n\n";

    switch (checkNumber()) {
    case 1:
        return 9;
    case 2:
        return 16;
    case 3:
        return 24;
    }
}
int Menu::start() {
    return (displayMenu());
}