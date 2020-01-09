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
    // dau cua goc point1 point0 point2
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
    // Khai bao bien.
    std::vector<cv::Point> points;
    for (size_t i = 0; i < 15; ++i)
    {
        points.push_back(cv::Point(100 + rand() % 400, 100 + rand() % 200)); //tim cac so >100, <500 ngau nhien. so luong tim kiemm nho hon i.
    }
    for (size_t i = 0; i < points.size(); ++i)
    {
        std::cout << i << ": " << points[i] << std::endl; //Hien ra man hinh cac so ngau nhien vua tim.
    }
    //Khai bao bien.
    std::vector<cv::Point> convex_hulls;
    //Tim gia tri co  x nho nhat trong day so ngau nhien..
    cv::Point min_x_point = points[0];
    for (size_t i = 0; i < points.size(); ++i)
    {
        if (min_x_point.x > points[i].x)
        {
            min_x_point = points[i];
        }
    }
    convex_hulls.push_back(min_x_point); //Day gia  tri min_x_point vao convex_hull.

    while (true)
    {
        cv::Point latest_peak = convex_hulls[convex_hulls.size() - 1];
        cv::Point next_peak;
        bool is_next_point_existing = false;
        for (size_t i = 0; i < points.size(); ++i)
        {
            cv::Point current_point = points[i];
            bool get_sign_convex_hulls = true;
            for (size_t j = 0; j < convex_hulls.size(); ++j)
            {
                if (current_point.x == convex_hulls[j].x && current_point.y == convex_hulls[j].y) //xet diem hien tai va cac diem trong convex_hull. loai bo cac diem da xet truoc do.
                {
                    get_sign_convex_hulls = false;
                    break;
                }
            }
            if (get_sign_convex_hulls == true) //Neu diem hien tai khac cac diem da xet truoc do.
            {
                std::cout << i << " " << current_point << std::endl;
                bool is_next_peak = true;
                for (size_t j = 0; j < points.size(); ++j)
                {
                    if (get_sign_angle(current_point, latest_peak, points[j]) > 0) //Xet dau. Tim cac diem thoa man yeu cau(so sanh voi current_point)
                    {
                        is_next_peak = false;
                        break;
                    }
                }
                if (is_next_peak == true)
                {
                    is_next_point_existing = true;
                    next_peak = current_point; //Neu thoa man thi gan next_peak = current_point.
                }
            }
        }
        if (is_next_point_existing) //Chay truong trinh trong khi ton tai diem tiep theo. neu khong ton tai thi dung chuong trinh.
        {
            convex_hulls.push_back(next_peak); //Day tat cac cac gia tri thoa man vao convex_hull
        }
        else //Neu khong con diem nao de xet thi dung lai.
        {
            break;
        }
    }
    //

    for (size_t i = 0; i < convex_hulls.size(); ++i)
    {
        std::cout << i << ": " << convex_hulls[i] << std::endl; //Hien ra man hinh tat ca gia tri trong convex_hull.
    }
    //Ve hinh
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
    cv::flip(image, image, 0);
    cv::imshow("image", image);
    cv::waitKey();

    return 0;
}