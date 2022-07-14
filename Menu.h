#pragma once
#include <string>

class Menu
{
public:
    int number{};
    std::string inputNumber{};
    int start();

private:
    bool checkNumbers(char c);
    int checkNumber();
    int displayMenu();
};