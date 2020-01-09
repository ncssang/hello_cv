#include "hello_cv/geometry.hpp"

Point::Point(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Point::print()
{
    std::cout << x << " " << y << std::endl;
}

void Circle::print()
{
    std::cout << centre.x << " ";
    std::cout << centre.y << " ";
    std::cout << radius << std::endl;
}

float get_perimeter(float a, float b, float c)
{
    return (a + b + c);
}

float get_area(float a, float b, float c)
{
    float half_p = get_perimeter(a, b, c) / 2;
    float area = sqrt(half_p * (half_p - a) * (half_p - b) * (half_p - c));
    return area;
}

bool is_a_triangle(float a, float b, float c)
{
    bool is_triangle;
    if (a + b < c || a + c < b || b + c < a)
    {
        is_triangle = false;
    }
    else
    {
        is_triangle = true;
    }

    return is_triangle;
}

float get_euclid_distance(Point point_1, Point point_2)
{
    float d_x = point_1.x - point_2.x;
    float d_y = point_1.y - point_2.y;
    float distance = sqrt(d_x * d_x + d_y * d_y);
    return distance;
}

Point3d::Point3d(float input_x, float input_y, float input_z)
{
    // std::cout << "Constructor\n";
    x = input_x;
    y = input_y;
    z = input_z;
}

void Point3d::print()
{
    std::cout << x << " " << y << " " << z << std::endl;
}

float get_euclid_distance_squared(Point3d point_1, Point3d point_2)
{
    float d_x = point_1.x - point_2.x;
    float d_y = point_1.y - point_2.y;
    float d_z = point_1.z - point_2.z;
    float distance_squared = d_x * d_x + d_y * d_y + d_z * d_z;
    return distance_squared;
}

float get_standard_deviation(std::vector<Point3d> points)
{
    Point3d average_point;
    average_point.x = 0;
    average_point.y = 0;
    average_point.z = 0;
    for (size_t i = 0; i < points.size(); ++i)
    {
        average_point.x += points[i].x;
        average_point.y += points[i].y;
        average_point.z += points[i].z;
    }
    average_point.x = average_point.x / points.size();
    average_point.y = average_point.y / points.size();
    average_point.z = average_point.z / points.size();
    // average_point.x /= points.size();
    // average_point.x /= points.size();
    average_point.print();
    // average_point.add_one();
    // average_point.print();

    float D = 0;
    for (size_t i = 0; i < points.size(); ++i)
    {
        D += get_euclid_distance_squared(points[i], average_point);
    }
    float SD;
    SD = sqrt(D / (points.size() - 1));

    return SD;
}

Plane::Plane(float default_a, float default_b, float default_c, float default_d)
    : a(default_a), b(default_b), c(default_c), d(default_d)
{
    // std::cout << "Constructor\n";
}

void Plane::print()
{
    std::cout << a << " " << b << " " << c << " " << d << "\n";
}

Line::Line(float input_a, float input_b, float input_c)
    : a(input_a), b(input_b), c(input_c)
{
}

void Line::print()
{
    std::cout << a << "*x + " << b << "*y + " << c << " = 0" << std::endl;
}

Line get_line_equation(Point point_1, Point point_2)
{
    Point direction;
    direction.x = point_2.x - point_1.x;
    direction.y = point_2.y - point_1.y;
    Point normal(-direction.y, direction.x);
    // normal.x = -direction.y;
    // normal.y = direction.x;
    Line line;
    line.a = normal.x;
    line.b = normal.y;
    line.c = -(normal.x * point_1.x + normal.y * point_1.y);

    // Tim he so line.a, line.b, line.c

    return line;
}

Point get_triangle_centre(Point A, Point B, Point C)
{
    Point M;
    M.x = (C.x + B.x) / 2;
    M.y = (C.y + B.y) / 2;

    Point v_AM;
    v_AM.x = (M.x - A.x);
    v_AM.y = (M.y - A.y);
    Point v_AI;
    v_AI.x = (2.0 / 3) * v_AM.x;
    v_AI.y = (2.0 / 3) * v_AM.y;

    Point I;
    I.x = A.x + v_AI.x;
    I.y = A.y + v_AI.y;

    return I;
}

int get_point_sign_on_plane(Point point, Line line)
{
    float left_side_line = line.a * point.x + line.b * point.y + line.c;
    if (left_side_line > 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

bool are_points_on_same_side(Point point_1, Point point_2, Line line)
{
    int sign_point_1 = get_point_sign_on_plane(point_1, line);
    int sign_point_2 = get_point_sign_on_plane(point_2, line);
    if (sign_point_1 * sign_point_2 > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_point_inside_triangle(Point point, Point A, Point B, Point C)
{
    Line line_AB = get_line_equation(A, B);
    Line line_BC = get_line_equation(B, C);
    Line line_CA = get_line_equation(C, A);
    Point centre_ABC = get_triangle_centre(A, B, C);

    if (are_points_on_same_side(point, centre_ABC, line_AB) &&
        are_points_on_same_side(point, centre_ABC, line_BC) &&
        are_points_on_same_side(point, centre_ABC, line_CA))
    {
        return true;
    }
    else
    {
        return false;
    }
}
