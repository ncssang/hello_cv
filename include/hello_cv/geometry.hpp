#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <cmath>
#include <iostream>
#include <vector>

struct Point
{
    float x;
    float y;

public:
    Point(float x = 0, float y = 0);
    void print();
};
struct Circle
{
    Point centre;
    float radius;

    void print();
};

float get_perimeter(float a, float b, float c);
float get_area(float a, float b, float c);
bool is_a_triangle(float a, float b, float c);

float get_euclid_distance(Point point_1, Point point_2);

struct Point3d
{
    float x;
    float y;
    float z;

    Point3d(float input_x = 0, float input_y = 0, float input_z = 0);
    void print();
};

float get_euclid_distance_squared(Point3d point_1, Point3d point_2);

float get_standard_deviation(std::vector<Point3d> points);

struct Plane
{
    float a;
    float b;
    float c;
    float d;

    Plane(float default_a = 1, float default_b = 1, float default_c = 1, float default_d = 1);
    void print();
};

struct Line
{
    float a;
    float b;
    float c;

public:
    Line(float input_a = 1, float input_b = 1, float input_c = 0);
    void print();
};

Line get_line_equation(Point point_1, Point point_2);
Point get_triangle_centre(Point A, Point B, Point C);
int get_point_sign_on_plane(Point point, Line line);
bool are_points_on_same_side(Point point_1, Point point_2, Line line);
bool is_point_inside_triangle(Point point, Point A, Point B, Point C);

#endif // GEOMETRY_HPP
