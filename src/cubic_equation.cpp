#include <cmath>
#include <iostream>

class Cubic_equation
{
private:
    float a, b, c, d;

public:
    Cubic_equation(float a = 0, float b = 0, float c = 0, float d = 0);
    void get_cubic_equation();
    float gets(float x);
    float binary_search(float number_1, float number_2);
};

int main()
{
    float a, b, c, d;
    do
    {
        std::cout << "Nhập a: ";
        std::cin >> a;
        std::cout << "Nhập b: ";
        std::cin >> b;
        std::cout << "Nhập c: ";
        std::cin >> c;
        std::cout << "Nhập d: ";
        std::cin >> d;
    } while (a == 0);
    std::cout << "Hàm số  đã nhập: y = " << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << std::endl;
    Cubic_equation Ham_so(a, b, c, d);
    Ham_so.get_cubic_equation();
}

Cubic_equation::Cubic_equation(float a, float b, float c, float d)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
}

float Cubic_equation::binary_search(float number_1, float number_2)
{
    while (number_1 < number_2)
    {
        float mid_number = (number_1 + number_2) / 2;
        float mid_value = gets(mid_number);
        float value_1 = gets(number_1);
        float delta = 1e-5;
        float absolute_value = mid_number - number_1;
        if (-delta < absolute_value && absolute_value < delta)
        {
            return mid_number;
            break;
        }

        if (mid_value == 0)
        {
            return mid_number;
        }
        else if (value_1 == 0)
        {
            return number_1;
        }
        else if (mid_value * value_1 > 0)
        {
            number_1 = mid_number;
        }
        else
        {
            number_2 = mid_number;
        }
    }
    return -1;
}

float Cubic_equation::gets(float x)
{
    float y = a * x * x * x + b * x * x + c * x + d;
    return y;
}

void Cubic_equation::get_cubic_equation()
{

    std::cout << "Hàm số  đã cho có tập xác định là: R." << std::endl;
    float de_a, de_b;
    de_a = 3 * a;
    de_b = 2 * b;
    std::cout << "y' = " << de_a << "x^2 + " << de_b << "x + " << c << std::endl;
    float delta, x_I, y_I;
    delta = de_b * de_b - 4 * de_a * c;
    x_I = -b / (3 * a);
    y_I = gets(x_I);
    if (delta < 0)
    {
        if (a > 0)
        {
            std::cout << "Hàm số  đồng biến trong (-oo ; +oo)." << std::endl;
            std::cout << "Lim(y) khi x tiến tới -oo = -oo" << std::endl;
            std::cout << "Lim(y) khi x tiến tới +oo = +oo" << std::endl;
            std::cout << "Điểm uốn của đồ thị là: I = (" << x_I << "; " << y_I << ")" << std::endl;
            float nghiem = binary_search(-100, 100);
            std::cout << "Phuong trinh da cho co 1 nghiem = " << nghiem << std::endl;
        }
        else
        {
            std::cout << "Hàm số  nghịch biến trong (-oo ; +oo)." << std::endl;
            std::cout << "Lim(y) khi x tiến tới -oo = +oo" << std::endl;
            std::cout << "Lim(y) khi x tiến tới +oo = -oo" << std::endl;
            std::cout << "Điểm uốn của đồ thị là: I = (" << x_I << "; " << y_I << ")" << std::endl;
            float nghiem = binary_search(-100, 100);
            std::cout << "Phuong trinh da cho co 1 nghiem = " << nghiem << std::endl;
        }
    }
    else if (delta == 0)
    {
        if (a > 0)
        {
            std::cout << "HÀm số  đồng biến trong (-oo ; +oo)." << std::endl;
            std::cout << "Lim(y) khi x tiến tới -oo = -oo" << std::endl;
            std::cout << "Lim(y) khi x tiến tới +oo = +oo" << std::endl;
            std::cout << "Điểm uốn của đồ thị là: I = (" << x_I << "; " << y_I << ")" << std::endl;
            float nghiem = binary_search(-100, 100);
            std::cout << "Phuong trinh da cho co 1 nghiem = " << nghiem << std::endl;
        }
        else
        {
            std::cout << "Hàm số  nghịch biến trong (-oo ; +oo)." << std::endl;
            std::cout << "Lim(y) khi x tiến tới -oo = +oo" << std::endl;
            std::cout << "Lim(y) khi x tiến tới +oo = -oo" << std::endl;
            std::cout << "Điểm uốn của đồ thị là: I = (" << x_I << "; " << y_I << ")" << std::endl;
            float nghiem = binary_search(-100, 100);
            std::cout << "Phuong trinh da cho co 1 nghiem = " << nghiem << std::endl;
        }
    }
    else
    {
        float x_1, x_2, y_1, y_2, sqrt_delta;
        sqrt_delta = sqrt(delta);
        x_1 = (-de_b + sqrt_delta) / (2 * de_a);
        x_2 = (-de_b - sqrt_delta) / (2 * de_a);
        if (x_1 > x_2)
        {
            float temp = x_2;
            x_2 = x_1;
            x_1 = temp;
        }
        y_1 = gets(x_1);
        y_2 = gets(x_2);
        if (a > 0)
        {
            std::cout << "Hàm số  đạt cực đại tại: (" << x_1 << "; " << y_1 << ")" << std::endl;
            std::cout << "Hàm số đạt cực tiểu tại: (" << x_2 << "; " << y_2 << ")" << std::endl;
            std::cout << "Lim(y) khi x tiến tới -oo = -oo" << std::endl;
            std::cout << "Lim(y) khi x tiến tới +oo = +oo" << std::endl;
            std::cout << "Hàm số  đồng biến trong: [-oo ; " << x_1 << "] & [" << x_2 << " ; +oo]" << std::endl;
            std::cout << "Hàm số  nghịch biến trong: [" << x_1 << "; " << x_2 << "]" << std::endl;
            std::cout << "Điểm uốn của đồ thị là: I = (" << x_I << "; " << y_I << ")" << std::endl;
            if (y_1 == 0)
            {
                float nghiem = binary_search(x_2, 1000);
                std::cout << "Ham so da cho co 2 nghiem: x_1 = " << x_1 << " & x_2 = " << nghiem << std::endl;
            }
            else if (y_2 == 0)
            {
                float nghiem = binary_search(-1000, x_1);
                std::cout << "Ham so da cho co 2 nghiem: x_1 = " << x_2 << " & x_2 = " << nghiem << std::endl;
            }
            else
            {
                float nghiem_1 = binary_search(-1000, x_1);
                float nghiem_2 = binary_search(x_1, x_2);
                float nghiem_3 = binary_search(x_2, 1000);
                std::cout << "Ham so da cho co 3 nghiem: x_1 = " << nghiem_1 << " & x_2 = " << nghiem_2 << " & x_3 = " << nghiem_3 << std::endl;
            }
        }
        else
        {
            std::cout << "Hàm số  đạt cực đại tại: (" << x_2 << "; " << y_2 << ")" << std::endl;
            std::cout << "Hàm số đạt cực tiểu tại: (" << x_1 << "; " << y_1 << ")" << std::endl;
            std::cout << "Lim(y) khi x tiến tới -oo = +oo" << std::endl;
            std::cout << "Lim(y) khi x tiến tới +oo = -oo" << std::endl;
            std::cout << "Hàm số  đồng biến trong: [" << x_1 << "; " << x_2 << "]" << std::endl;
            std::cout << "Hàm số  nghịch biến trong: [-oo ; " << x_1 << "] & [" << x_2 << " ; +oo]" << std::endl;
            std::cout << "Điểm uốn của đồ thị là: I = (" << x_I << "; " << y_I << ")" << std::endl;
            if (y_1 == 0)
            {
                float nghiem = binary_search(x_2, 1000);
                std::cout << "Ham so da cho co 2 nghiem: x_1 = " << x_1 << " & x_2 = " << nghiem << std::endl;
            }
            else if (y_2 == 0)
            {
                float nghiem = binary_search(-1000, x_1);
                std::cout << "Ham so da cho co 2 nghiem: x_1 = " << x_2 << " & x_2 = " << nghiem << std::endl;
            }
            else
            {
                float nghiem_1 = binary_search(-1000, x_1);
                float nghiem_2 = binary_search(x_1, x_2);
                float nghiem_3 = binary_search(x_2, 1000);
                std::cout << "Ham so da cho co 3 nghiem: x_1 = " << nghiem_1 << " & x_2 = " << nghiem_2 << " & x_3 = " << nghiem_3 << std::endl;
            }
        }
    }
}