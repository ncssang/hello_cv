#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int frequency1 = 0;
    int frequency2 = 0;
    int frequency3 = 0;
    int frequency4 = 0;
    int frequency5 = 0;
    int frequency6 = 0;

    int roll;
    int face;

    for (roll = 1; roll <= 6000; ++roll)
    {
        face = 1 + rand() % 6;
        switch (face)
        {
            case 1:
            {
                ++frequency1;
                break;
            }
            case 2:
            {
                ++frequency2;
                break;
            }
            case 3:
            {
                ++frequency3;
                break;
            }
            case 4:
            {
                ++frequency4;
                break;
            }
            case 5:
            {
                ++frequency5;
                break;
            }
            case 6:
            {
                ++frequency6;
                break;
            }
        }
    }

    std::cout << "1: " << frequency1 << std::endl;
    std::cout << "2: " << frequency2 << std::endl;
    std::cout << "3: " << frequency3 << std::endl;
    std::cout << "4: " << frequency4 << std::endl;
    std::cout << "5: " << frequency5 << std::endl;
    std::cout << "6: " << frequency6 << std::endl;
    return 0;
}