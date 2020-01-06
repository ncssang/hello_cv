#include <iostream>

#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>

int get_sign_angle(cv::Point point_1, cv::Point point_0, cv::Point point_2)
{
    // dau cua goc point1 point2 point3
    cv::Point v_p0_p1;
    v_p0_p1.x = point_1.x - point_0.x;
    v_p0_p1.y = point_1.y - point_0.y;
    cv::Point v_p0_p2;
    v_p0_p2.x = point_2.x - point_0.x;
    v_p0_p2.y = point_2.y - point_0.y;
    float sign_vp0p1_vp0p2;
    sign_vp0p1_vp0p2 = v_p0_p1.x * v_p0_p2.y - v_p0_p2.x * v_p0_p1.y;
    if (sign_vp0p1_vp0p2 > 0)
    {
        sign_vp0p1_vp0p2 = 1;
    }
    else
    {
        sign_vp0p1_vp0p2 = -1;
    }
    return sign_vp0p1_vp0p2;
}

int main()
{

    std::vector<cv::Point> points;
    for (size_t i = 0; i < 5; ++i)
    {
        points.push_back(cv::Point(100 + rand() % 400, 100 + rand() % 200));
    }
    for (size_t i = 0; i < points.size(); ++i)
    {
        std::cout << i << ": " << points[i] << std::endl;
    }

    std::vector<cv::Point> convex_hulls;
    cv::Point min_x_point = points[0];
    for (size_t i = 0; i < points.size(); ++i)
    {
        if (min_x_point.x > points[i].x)
        {
            min_x_point = points[i];
        }
    }
    std::cout << min_x_point << std::endl;
    convex_hulls.push_back(min_x_point);

    while (true)
    {
        cv::Point latest_peak = convex_hulls[convex_hulls.size() - 1];
        // std::cout << " latest_peak: " << latest_peak << std::endl;

        cv::Point next_peak(50, 50);
        bool is_next_point_existing = false;
        for (size_t i = 0; i < points.size(); ++i)
        {
            cv::Point current_point = points[i];
            bool get_sign_convex_hulls = true;
            for (size_t j = 0; j < convex_hulls.size(); ++j)
            {
                if (current_point.x == convex_hulls[j].x && current_point.y == convex_hulls[j].y)
                {
                    get_sign_convex_hulls = false;
                    break;
                }
            }
            if (get_sign_convex_hulls == true)
            {
                std::cout << i << " " << current_point << std::endl;
                bool is_next_peak = true;
                for (size_t j = 0; j < points.size(); ++j)
                {
                    if (get_sign_angle(current_point, latest_peak, points[j]) > 0)
                    {
                        is_next_peak = false;
                        break;
                    }
                }
                if (is_next_peak == true)
                {
                    is_next_point_existing = true;
                    next_peak = current_point;
                }
            }
        }
        if (is_next_point_existing)
        {
            convex_hulls.push_back(next_peak);
        }
        else
        {
            break;
        }
    }
    //

    for (size_t i = 0; i < convex_hulls.size(); ++i)
    {
        std::cout << i << ": " << convex_hulls[i] << std::endl;
    }

    cv::Mat image = cv::Mat::zeros(cv::Size(600, 400), CV_8UC3);
    for (size_t i = 0; i < points.size(); ++i)
    {
        cv::circle(image, points[i], 2, cv::Scalar(0, 255, 0), -1, 8);
    }
    for (size_t i = 0; i < convex_hulls.size() - 1; ++i)
    {
        cv::line(image, convex_hulls[i], convex_hulls[i + 1], 255, 1, 8);
    }
    cv::line(image, convex_hulls[0], convex_hulls[convex_hulls.size() - 1], 255, 1, 8);

    cv::imshow("image", image);
    cv::waitKey();

    return 0;
}