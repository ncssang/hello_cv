#include <iostream>

void Tower(int n, char a, char b, char c);

int main()
{
    char a = 'A';
    char b = 'B';
    char c = 'C';
    int n;
    std::cout << "Nhap n: ";
    std::cin >> n;

    Tower(n, a, b, c);
}

void Tower(int n, char a, char b, char c)
{
    if (n == 1)
    {
        std::cout << a << "-------" << c << std::endl;
        return;
    }
    else
    {
        Tower(n - 1, a, c, b);
        Tower(1, a, b, c);
        Tower(n - 1, b, a, c);
    }
}