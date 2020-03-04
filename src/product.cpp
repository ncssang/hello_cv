#include <iostream>

int main()
{
    int N;
    do
    {
        std::cout << "Nhap N: ";
        std::cin >> N;
    } while (N % 2 != 0 && N > 0);

    int s = 0;
    int k = N / 2;
    for (int i = 0; i <= k; ++i)
    {
        int ni = 2 * i;
        if (i % 2 == 0)
        {
            s += -ni * ni;
        }
        else
        {
            s += ni * ni;
        }
    }
    std::cout << "S = " << s << std::endl;
}

//cin >> n;
// k = n /2;
// s =0;
//for( int i = 0; i < k; ++i)
//{ni = 2*i; if