#include <iostream>
#include "Game.h"
#include <string>

int rozmiar{};
std::string inputRozmiar{};

bool checkNumbers(char c)
{
    return c >= '0' && c <= '9';
}

bool checkRozmiarValue()
{
    if (rozmiar > 3 || rozmiar <1)
    {
        std::cout << "The entered value should be in range 1-3, try again: ";
    }

    return (rozmiar <= 3 && rozmiar >= 1);
}

int checkRozmiar(){
    do
    {
        std::cin >> inputRozmiar; 

        //check char-by-char if inputed value is an positive integer
        for (int i = 0; not inputRozmiar.empty() && (i <= inputRozmiar.length() - 1); i++)
        {
            if (checkNumbers(inputRozmiar[i]))
            {
                continue;
            }
            else
            {
                std::cout << "\nThe entered value is incorrect." << std::endl;
                inputRozmiar.clear();
                break;
            }
        }

        if (not inputRozmiar.empty())
        {
            rozmiar = std::stoi(inputRozmiar);
            inputRozmiar.clear();
        }
    } while (not checkRozmiarValue());

    return rozmiar;
}



int main() {
    
  
    std::cout << "Choose lvl;";
    std::cout << "1. Begginer";
    std::cout << "2. Begginer";
    std::cout << "3. Begginer";
    
    checkRozmiar();

    Game game(rozmiar);

}