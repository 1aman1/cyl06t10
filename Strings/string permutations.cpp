#include <iostream>

void make_permutation(std::string str, int l, int r)
{
    if (l == r)
        std::cout << str << std::endl;

    for (int i = l; i <= r; ++i)
    {
        std::swap(str[i], str[l]);

        make_permutation(str, l + 1, r);

        std::swap(str[i], str[l]);
    }
}

int main()
{
    std::string str = "AMAN";
    make_permutation(str, 0, str.size() - 1);
    return 0;
}