#include <cmath>
#include <iostream>

#include "hello_cv/geometry.hpp"

Point get_intersection_of_bisectors(Point A, Point B, Point C);

int main()
{
    Point A, B, C;
    std::cout << "Nhap xA: ";
    std::cin >> A.x;
    std::cout << "Nhap yA: ";
    std::cin >> A.y;
    std::cout << "Nhap xB: ";
    std::cin >> B.x;
    std::cout << "Nhap yB: ";
    std::cin >> B.y;
    std::cout << "Nhap xC: ";
    std::cin >> C.x;
    std::cout << "Nhap yC: ";
    std::cin >> C.y;

    Point I = get_intersection_of_bisectors(A, B, C);
    std::cout << "I: ";
    I.print();
}

Point get_intersection_of_bisectors(Point A, Point B, Point C)
{
    float d_AB = get_euclid_distance(A, B);
    std::cout << "d_AB = " << d_AB << std::endl;
    float d_AC = get_euclid_distance(A, C);
    std::cout << "d_AC = " << d_AC << std::endl;
    float d_BC = get_euclid_distance(B, C);
    std::cout << "d_BC = " << d_BC << std::endl;

    Point D;
    D.x = A.x + (d_AB / d_AC) * (C.x - A.x);
    D.y = A.y + (d_AB / d_AC) * (C.y - A.y);
    Point M;
    M.x = (B.x + D.x) / 2;
    M.y = (B.x + D.x) / 2;
    Point v_AM;
    v_AM.x = M.x - A.x;
    v_AM.y = M.y - A.y;
    Point v_MH;
    v_MH.x = -v_AM.y;
    v_MH.y = v_AM.x;
    Line AM;
    AM.a = v_MH.x;
    AM.b = v_MH.y;
    AM.c = -v_MH.x * A.x - v_MH.y * A.y;

    Point E;
    E.x = B.x + (d_AB / d_BC) * (C.x - B.x);
    E.y = B.y + (d_AB / d_BC) * (C.y - B.y);
    Point K;
    K.x = (A.x + E.x) / 2;
    K.y = (A.y + E.y) / 2;
    Point v_BK;
    v_BK.x = K.x - B.x;
    v_BK.y = K.y - B.y;
    Point v_KZ;
    v_KZ.x = -v_BK.y;
    v_KZ.y = v_BK.x;
    Line BK;
    BK.a = v_KZ.x;
    BK.b = v_KZ.y;
    BK.c = -v_KZ.x * B.x - v_KZ.y * B.y;

    Point I;
    {
        float D, D_x, D_y;
        D = AM.a * BK.b - BK.a * AM.b;
        D_x = (-AM.c) * BK.b - (-BK.c) * AM.b;
        D_y = AM.a * (-BK.c) - BK.a * (-AM.c);

        if (D == 0)
        {
            if (D_x != 0 || D_y != 0)
            {
                std::cout << "Ba diem da cho khong phai la tam giac!" << std::endl;
            }
            else
            {
                std::cout << "Ba diem da cho khong phai la tam giac!" << std::endl;
            }
        }
        else
        {
            I.x = D_x / D;
            I.y = D_y / D;
        }
    }
    return I;
}
