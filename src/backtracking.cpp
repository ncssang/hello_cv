#include <cmath>
#include <iostream>
#include <vector>

class Queen
{
private:
    std::vector<int> positions;

public:
    Queen(int n);
    bool is_ok(int i, int j);
    void print_result();
    void backtrack(int i);
};

int main()
{
    Queen queen(8);
    queen.backtrack(0);
    return 0;
}

Queen::Queen(int n)
{
    positions = std::vector<int>(n, -1);
}

bool Queen::is_ok(int i, int j)
{
    for (int k = 0; k < i; ++k)
    {
        if (positions[k] == j || abs(k - i) == abs(positions[k] - j))
        {
            return false;
        }
    }
    return true;
}

void Queen::print_result()
{
    for (size_t i = 0; i < positions.size(); ++i)
    {
        std::cout << positions[i] << " ";
    }
    printf("\n");
}

void Queen::backtrack(int i)
{
    for (int j = 0; j < (int)positions.size(); ++j)
    {
        if (is_ok(i, j))
        {
            positions[i] = j;
            if (i == (int)(positions.size() - 1))
            {
                print_result();
            }
            else
            {
                backtrack(i + 1);
            }
        }
    }
}
