#include <iostream>
#include <bitset>

bool insert(int solvent, int doping, int i, int j)
{
    std::cout << std::bitset<8>(solvent) << " "
              << std::bitset<8>(doping)
              << std::endl;

    solvent = solvent | doping << i;

    std::cout << solvent << " "
              << std::bitset<8>(solvent)
              << std::endl;
}

int main()
{
    int m = 40;
    int n = 5;
    int i = 2;
    int j = 4;

    insert(m, n, i, j);

    return 0;
}