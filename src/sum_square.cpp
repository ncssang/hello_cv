#include <iostream>

int sum(int n);

int main()
{
    int n;
    std::cout << "Nhap n: ";
    std::cin >> n;
    std::cout << "Tong binh phuong cac so nho hon n = " << sum(n) << std::endl;
}

int sum(int n)
{
    int s = 0;
    for (int i = 1; i <= n; ++i)
    {
        s += i * i;
    }
    return s;
}
