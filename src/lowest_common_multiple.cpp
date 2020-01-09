#include <iostream>
#include <cmath>

int GCD(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
};
int main()
{
    int a, b;
    std::cout << "Nhap a: ";
    std::cin >> a;
    std::cout << "Nhap b: ";
    std::cin >> b;
    int GCM = GCD(a, b);
    std::cout << "Greatest common divisor: " << GCM << std::endl;
    int LCM = (a * b) / GCM;
    std::cout << "Lowest common multiple: " << LCM << std::endl;
}