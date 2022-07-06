#include <iostream>

bool isPowerof2(int n)
{
    return ((n & (n - 1)) == 0);
}

int main()
{
    int m = 15;
    int n = 16;

    // It checks if a number is a power of 2

    std::cout << std::boolalpha << isPowerof2(m) << std::endl;
    std::cout << std::boolalpha << isPowerof2(n) << std::endl;

    return 0;
}