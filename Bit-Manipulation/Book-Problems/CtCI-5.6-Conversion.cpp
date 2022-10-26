#include <iostream>
#include <bitset>

bool method2(int number, int Kth)
{
    return (number & (1 << Kth));
}

void findConversionBits(int m, int n)
{
    while (m > 0)
    {
        std::cout << std::bitset<8>(m) << " "
                  << std::bitset<8>(n)
                  << std::endl;

        m = m >> 1;
        n = n >> 1;
    }
}

int main()
{
    int m = 15;
    int n = 16;

    std::cout << std::bitset<8>(m) << " "
              << std::bitset<8>(n)
              << std::endl;

    findConversionBits(m, n);

    return 0;
}