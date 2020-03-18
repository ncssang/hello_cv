#include <iostream>

int exponential(int a, int b);
int factorial(int a);

int main()
{
    int a, b;
    std::cout << "Nhap a:";
    std::cin >> a;
    std::cout << "Nhap b:";
    std::cin >> b;
    int expo = exponential(a, b);
    std::cout << a << "^" << b << " = " << expo << std::endl;
    int fac_1 = factorial(a);
    std::cout << a << "!" << " = " << fac_1 << std::endl;
    int fac_2 = factorial(b);
    std::cout << b << "!" << " = " << fac_2 << std::endl;
}
int factorial(int a)
{
    int factorial = 1;
    for (int i = 0; i < a; ++i)
    {
        factorial = factorial * (a - i);
    }
    return factorial;
}

int exponential(int a, int b)
{
    int expo = 1;
    for (int i = 1; i <= b; ++i)
    {
        expo = expo * a;
    }
    return expo;
}