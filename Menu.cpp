#include "Menu.h"
#include <iostream>
#include <string>


bool Menu::checkNumbers(char c) {
    return c >= '0' && c <= '9';
}

bool Menu::checkRozmiarValue() {
    if (rozmiar > 3 || rozmiar < 1) {
        std::cout << "The entered value should be in range 1-3, try again: ";
    }

    return (rozmiar <= 3 && rozmiar >= 1);
}

int Menu::checkRozmiar() {
    do {
        std::cin >> inputRozmiar;

        //check char-by-char if inputed value is an positive integer
        for (int i = 0; not inputRozmiar.empty() && (i <= inputRozmiar.length() - 1); i++) {
            if (checkNumbers(inputRozmiar[i])) {
                continue;
            }
            else {
                std::cout << "\nThe entered value is incorrect." << std::endl;
                inputRozmiar.clear();
                break;
            }
        }

        if (not inputRozmiar.empty()) {
            rozmiar = std::stoi(inputRozmiar);
            inputRozmiar.clear();
        }
    } while (not checkRozmiarValue());

    return rozmiar;
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
    std::cout << "3. Advanced\n";

    switch (checkRozmiar()) {
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