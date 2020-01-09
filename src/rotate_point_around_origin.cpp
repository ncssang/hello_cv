#include <cmath>
#include <iostream>

#include "hello_cv/geometry.hpp"

Point rotate(Point A, float angle);
Point rotate_AX(Point A, Point X, float angle);

int main()
{
    Point A(2, 3);
    A.print();
    Point X(1, 2);
    Point Q = rotate(A, 90);
    Q.print();
    Point P = rotate_AX(A, X, 90);
    P.print();
}

Point rotate(Point A, float angle)
{
    float rad = (angle * M_PI) / 180;
    Point B;
    B.x = A.x * cos(rad) - A.y * sin(rad);
    B.y = A.x * sin(rad) + A.y * cos(rad);
    return B;
}

Point rotate_AX(Point A, Point X, float angle)
{
    Point A1;
    A1.x = A.x - X.x;
    A1.y = A.y - X.y;
    Point P = rotate(A1, angle);
    P.x += X.x;
    P.y += X.y;
    return P;
}
