#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

struct Worker
{
    std::string name;
    int salary;
    int age;
};
int main()
{
    int n;
    std::cout << "Nhap so cong nhan: " << std::endl;
    std::cin >> n;
    std::vector<Worker> workers;
    Worker worker;
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Nhap ten: ";
        std::cin >> worker.name;
        std::cout << "Nhap tuoi: ";
        std::cin >> worker.age;
        std::cout << "Nhap luong: ";
        std::cin >> worker.salary;
        workers.push_back(worker);
    }

    for (int j = 0; j < n; ++j)
    {
        for (int i = 0; i < n - 1 - j; ++i)
        {
            if (workers[i].salary > workers[i + 1].salary)
            {
                int temp = workers[i + 1].salary;
                workers[i + 1].salary = workers[i].salary;
                workers[i].salary = temp;
                std::string Name = workers[i + 1].name;
                workers[i + 1].name = workers[i].name;
                workers[i].name = Name;
            }
        }
    }
    std::cout << "Nguoi co Luong cao nhat la: " << workers[n - 1].name << "  " << workers[n - 1].salary << std::endl;

    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += workers[i].salary;
    }
    float average = sum / n;
    for (int i = 0; i < n; ++i)
    {
        if (workers[i].salary > average)
        {
            std::cout << "cong nhan co luong tren trung binh la: " << workers[i].name << ": " << workers[i].salary << std::endl;
        }
    }

    std::ofstream output_file_stream;
    output_file_stream.open("output_1.txt");
    for (int i = 0; i < n; ++i)
    {
        output_file_stream << workers[i].name << "  " << workers[i].age << "  " << workers[i].salary << std::endl;
    }
    output_file_stream.close();
}