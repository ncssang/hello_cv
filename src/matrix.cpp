#include <iostream>
#include <stdio.h>
#include <vector>

class Matrix
{
private:
    int rows;
    int cols;

public:
    std::vector<std::vector<int>> data;

    Matrix(int rows = 0, int cols = 0);
    ~Matrix();
    void nhap_ma_tran();
    void print();
    int get_rows() const;
    int get_cols() const;
};

Matrix::Matrix(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    for (int i = 0; i < rows; ++i)
    {
        std::vector<int> row_matrix;
        for (int j = 0; j < cols; ++j)
        {
            row_matrix.push_back(0);
        }
        data.push_back(row_matrix);
    }
}

void Matrix::nhap_ma_tran()
{
    std::cout << "Nhap so hang: ";
    std::cin >> rows;
    std::cout << "Nhap so cot: ";
    std::cin >> cols;
    for (int i = 0; i < rows; ++i)
    {
        std::vector<int> row_data;
        for (int j = 0; j < cols; ++j)
        {
            std::cout << "Nhap phan tu[" << i << "][" << j << "] = ";
            int value;
            std::cin >> value;
            row_data.push_back(value);
        }
        data.push_back(row_data);
    }
}

Matrix::~Matrix()
{
    // printf("Destructor.\n");
}

void Matrix::print()
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << data[i][j] << "\t";
        }
        std::cout << "\n";
    }
}
Matrix multiple_matrix(Matrix matrix_a, Matrix matrix_b)
{

    Matrix matrix(matrix_a.get_rows(), matrix_b.get_cols());

    for (int i = 0; i < matrix_a.get_rows(); ++i)
    {
        for (int j = 0; j < matrix_b.get_cols(); ++j)
        {
            for (int k = 0; k < matrix_a.get_cols(); ++k)
            {
                matrix.data[i][j] += matrix_a.data[i][k] * matrix_b.data[k][j];
            }
        }
    }
    return matrix;
}

int Matrix::get_rows() const
{
    return rows;
}
int Matrix::get_cols() const
{
    return cols;
}

int main()
{
    Matrix matrix_a;
    matrix_a.nhap_ma_tran();
    matrix_a.print();

    Matrix matrix_b;
    matrix_b.nhap_ma_tran();
    matrix_b.print();
    std::cout << "\n";

    if (matrix_a.get_cols() == matrix_b.get_rows())
    {
        Matrix matrix_c;
        matrix_c = multiple_matrix(matrix_a, matrix_b);
        matrix_c.print();
    }
    else
    {
        std::cout << "Khong the nhan 2 ma tran!" << std::endl;
    }
    return 0;
}
