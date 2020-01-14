#include <cmath>
#include <iostream>

#include <vector>
int binary_search(std::vector<int> numbers, int x)
{
    int left_index = 0;
    int right_index = numbers.size() - 1;
    while (left_index <= right_index)
    {
        int mid_index = (left_index + right_index) / 2;
        if (x == numbers[mid_index])
        {
            //mid_index = 2
            while (x == numbers[mid_index - 1])
            {
                mid_index = mid_index - 1;
                if (mid_index == 0)
                {
                    break;
                }
            }
            return mid_index;
        }
        else if (x < numbers[mid_index])
        {
            right_index = mid_index - 1;
        }
        else if (x > numbers[mid_index])
        {
            left_index = mid_index + 1;
        }
    }
    return -1;
}
int main()
{
    std::vector<int> numbers;
    for (size_t i = 0; i < 100; ++i)
    {
        numbers.push_back(int(rand() % 200));
    }
    for (size_t i = 0; i < numbers.size(); ++i)
    {
        std::cout << i << ": " << numbers[i] << std::endl;
    }
    for (int j = 0; j < (int)(numbers.size() - 1); ++j)
    {
        for (int i = 0; i < (int)(numbers.size() - 1 - j); ++i)
        {
            if (numbers[i] > numbers[i + 1])
            {
                int temp = numbers[i + 1];
                numbers[i + 1] = numbers[i];
                numbers[i] = temp;
            }
        }
        for (size_t i = 0; i < numbers.size(); ++i)
        {
            std::cout << i << " : " << numbers[i] << std::endl;
        }
    }

    int x;
    std::cout << "Nhap x: ";
    std::cin >> x;

    int X = binary_search(numbers, x);
    if (X == -1)
    {
        std::cout << "Khong co gia tri x can tim." << std::endl;
    }
    else
    {
        std::cout << "Vi tri dau tien cua so " << x << ": " << X << std::endl;
    }
}
