#include <cmath>
#include <iostream>
#include <vector>

struct Point
{
    float x;
    float y;
    void print();
};

float get_multiplication_vector(Point point_1, Point point_2)
{
    float get_multiplication_vector = point_1.x * point_2.x + point_1.y * point_2.y;
    if(get_multiplication_vector == 0)
    {
        std::cout << "Hai vector vuong goc!";
    }
    else
    {
        std::cout << "Tich vo huong cua 2 vector la: " << get_multiplication_vector << std::endl;
    }
    return get_multiplication_vector;
    
};
int main()
{
    Point A, B;
    std::cout << "Nhap xA: ";
    std::cin >> A.x;
    std::cout << "Nhap yA: ";
    std::cin >> A.y;
    std::cout << "Nhap xB: ";
    std::cin >> B.x;
    std::cout << "Nhap yB: ";
    std::cin >> B.y;

    float D = get_multiplication_vector(A, B);
    std::cout << D;

}

