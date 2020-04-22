#include <iostream>
#include <stdio.h>
#include <vector>
#define MAX 8
#define CHUA_TOI_THAM 0
using namespace std;

class Knight
{
private:
    int size;
    std::vector<std::vector<int>> move;
    std::vector<std::vector<int>> path;
    std::vector<int> X;
    std::vector<int> Y;
    int buoc;
    int so_cach_di;

public:
    Knight(int size);
    void xuat();
    void diChuyen(int x, int y);
    int get_so_cach_di() const;
};

int main()
{
    cout << "Nhap size: ";
    int size;
    cin >> size;
    int a, b;
    cout << "Nhap vi tri ban dau.\nx: ";
    cin >> a;
    cout << "y: ";
    cin >> b;
    Knight knight(size);
    knight.diChuyen(a, b);
    std::cout << "So cach di: " << knight.get_so_cach_di();
}

Knight::Knight(int size)
{
    this->size = size;
    for (int i = 0; i < size; ++i)
    {
        std::vector<int> this_path(size, CHUA_TOI_THAM); // size phan tu voi gia tri mac dinh la CHUA_TOI_THAM
        // std::vector<int> this_path;
        // for (int j = 0; j < size; ++j)
        // {
        //     this_path.push_back(CHUA_TOI_THAM);
        // }
        path.push_back(this_path);
    }

    X = std::vector<int>{-2, -2, -1, -1, 1, 1, 2, 2};
    Y = std::vector<int>{-1, 1, -2, 2, -2, 2, -1, 1};
    move.push_back(X);
    move.push_back(Y);
    buoc = 0;
    so_cach_di = 0;
}

void Knight::xuat()
{
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                printf("%5d ", path[i][j]);
            }
            std::cout << endl;
        }
        std::cout << endl;
    }
}

void Knight::diChuyen(int x, int y)
{

    ++buoc;
    path[x][y] = buoc;

    if (buoc == size * size)
    {
        std::cout << "Cac buoc di la: \n";
        xuat();
        ++so_cach_di;
    }
    else
    {
        for (int i = 0; i < 8; i++)
        {
            int u = x + X[i];
            int v = y + Y[i];
            if (u >= 0 && u < size && v >= 0 && v < size && path[u][v] == CHUA_TOI_THAM)
            {
                diChuyen(u, v);
            }
        }
    }
    --buoc;
    path[x][y] = CHUA_TOI_THAM;
}

int Knight::get_so_cach_di() const
{
    return so_cach_di;
}