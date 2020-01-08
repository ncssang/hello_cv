#include <cmath>
#include <iostream>

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
    int GCM_ab = GCD(a, b);
    int a1, b1;
    a1 = a / GCM_ab;
    b1 = b / GCM_ab;
    std::cout << "Phan so toi gian cua a/b la: "
              << "a1/b1 = " << a1 << "/" << b1 << std::endl;

    int c, d;
    std::cout << "Nhap c: ";
    std::cin >> c;
    std::cout << "Nhap d: ";
    std::cin >> d;
    int GCM_cd = GCD(c, d);
    int c1, d1;
    c1 = c / GCM_cd;
    d1 = d / GCM_cd;
    std::cout << "Phan so toi gian cua c/d la: "
              << "c1/d1 = " << c1 << "/" << d1 << std::endl;

    int A, B;
    A = a1 * d1 + b1 * c1;
    B = b1 * d1;
    int GCM_AB = GCD(A, B);
    int A1, B1;
    A1 = A / GCM_AB;
    B1 = B / GCM_AB;
    std::cout << "Phan so toi gian cua A/B la: "
              << "A/B = " << A1 << "/" << B1 << std::endl;
}