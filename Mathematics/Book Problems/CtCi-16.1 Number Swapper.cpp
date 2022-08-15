#include <iostream>

/*
Without XOR
*/
void NumberSwapper(int &a, int &b)
{
    std::cout << "A:" << a << " B:" << b << std::endl;

    b = a - b;
    a = a - b;
    b = a + b;

    std::cout << "A:" << a
              << " B:" << b
              << std::endl
              << std::endl;
}

/*
Using XOR
*/
void XORNumberSwapper(int &a, int &b)
{
    std::cout << "A:" << a << " B:" << b << std::endl;

    b = a ^ b;
    a = a ^ b;
    b = a ^ b;

    std::cout << "A:" << a
              << " B:" << b
              << std::endl
              << std::endl;
}

int main()
{
    int a = 3;
    int b = 4;
    XORNumberSwapper(a, b);

    a = 3;
    b = -4;
    XORNumberSwapper(a, b);

    a = -3;
    b = 4;
    NumberSwapper(a, b);

    a = -3;
    b = -4;
    NumberSwapper(a, b);

    a = 4;
    b = 0;
    NumberSwapper(a, b);

    a = 0;
    b = 4;
    NumberSwapper(a, b);

    a = -3;
    b = 0;
    NumberSwapper(a, b);

    a = 0;
    b = -3;
    NumberSwapper(a, b);

    return 0;
}