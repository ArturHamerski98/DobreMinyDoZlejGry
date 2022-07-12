#pragma once
#include <string>



class Menu
{
public:
    int rozmiar{};
    std::string inputRozmiar{};
    int start();


private:
    bool checkNumbers(char c);
    bool checkRozmiarValue();
    int checkRozmiar();
    int displayMenu();
};