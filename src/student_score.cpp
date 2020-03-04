#include <iostream>
#include <vector>

struct Student
{
    std::string name;
    int score;
};


int main()
{

    std::vector<Student> students;
    Student student_1;
    std::cout << "Nhap ten: ";
    std::cin >> student_1.name;
    std::cout << "Nhap diem: ";
    std::cin >> student_1.score;
    students.push_back(student_1);
    Student student_2;
    std::cout << "Nhap ten: ";
    std::cin >> student_2.name;
    std::cout << "Nhap diem: ";
    std::cin >> student_2.score;
    students.push_back(student_2);
    Student student_3;
    std::cout << "Nhap ten: ";
    std::cin >> student_3.name;
    std::cout << "Nhap diem: ";
    std::cin >> student_3.score;
    students.push_back(student_3);
    Student student_4;
    std::cout << "Nhap ten: ";
    std::cin >> student_4.name;
    std::cout << "Nhap diem: ";
    std::cin >> student_4.score;
    students.push_back(student_4);
    Student student_5;
    std::cout << "Nhap ten: ";
    std::cin >> student_5.name;
    std::cout << "Nhap diem: ";
    std::cin >> student_5.score;
    students.push_back(student_5);
    Student student_6;
    std::cout << "Nhap ten: ";
    std::cin >> student_6.name;
    std::cout << "Nhap diem: ";
    std::cin >> student_6.score;
    students.push_back(student_6);


    std::cout << "Size: " << students.size() << std::endl;

    for (int j = 0; j < (int)(students.size() - 1); ++j)
    {
        for (int i = 0; i < (int)(students.size() - 1 - j); ++i)
        {
            if (students[i].score > students[i + 1].score)
            {
                int temp = students[i + 1].score;
                students[i + 1].score = students[i].score;
                students[i].score = temp;
                std::string Name = students[i +1].name;
                students[i + 1].name = students[i].name;
                students[i].name = Name;
            }
        }
    }

    for (size_t i = 0; i < students.size(); ++i)
    {
        std::cout << students[i].name << " : " << students[i].score << std::endl;
    }
}