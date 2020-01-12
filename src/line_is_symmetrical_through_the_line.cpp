#include <cmath>
#include <iostream>
#include <vector>

#include "hello_cv/geometry.hpp"

std::vector<Point> point_of_line_1(Line line_1)
{

    Point point_1, point_2;
    if (line_1.b == 0)
    {
        point_1.x = -line_1.c / line_1.a;
        point_1.y = 1;

        point_2.x = -line_1.c / line_1.a;
        point_2.y = 2;
    }
    else
    {
        point_1.x = 1;
        point_1.y = (-line_1.c - line_1.a * point_1.x) / line_1.b;

        point_2.x = 2;
        point_2.y = (-line_1.c - line_1.a * point_2.x) / line_1.b;
    }

    std::vector<Point> points;
    points.push_back(point_1);
    points.push_back(point_2);
    return points;
};

Point point_symmectical(Point point, Line line)
{
    // qua point_1 viet pt duong thang vuong goc voi line_1.
    Line line_2;
    line_2.a = - line.b;
    line_2.b = line.a;
    line_2.c = line.b * point.x - line.a * point.y;
 

    //hinh chieu cua point_1 len line 1 la nghiem cua he 2 pt.
    float D = line.a * line_2.b - line_2.a * line.b;
    float D_x = -line.c * line_2.b + line_2.c * line.b;
    float D_y = - line.a * line_2.c + line_2.a * line.c;
    Point A;
    A.x = D_x / D;
    A.y = D_y / D;
 

    Point A1;
    A1.x = 2 * A.x - point.x;
    A1.y = 2 * A.y - point.y;
    return A1;
};

int main()
{
    Line line_1;
    std::cout << "Nhap line_1.a: ";
    std::cin >> line_1.a;
    std::cout << "Nhap line_1.b: ";
    std::cin >> line_1.b;
    std::cout << "Nhap line_1.c: ";
    std::cin >> line_1.c;
    std::vector<Point> points = point_of_line_1(line_1);
    std::cout << points[0].x << " " << points[0].y << std::endl;
    std::cout << points[1].x << " " << points[1].y << std::endl;

    Line line_2;
    std::cout << "Nhap line_2.a: ";
    std::cin >> line_2.a;
    std::cout << "Nhap line_2.b: ";
    std::cin >> line_2.b;
    std::cout << "Nhap line_2.c: ";
    std::cin >> line_2.c;
    
    Point A = point_symmectical(points[0], line_2);
    A.print();
    Point B = point_symmectical(points[1], line_2);
    B.print();
    Line line_AB = get_line_equation(A, B);
    line_AB.print();
}