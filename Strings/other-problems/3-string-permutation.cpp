#include <iostream>
#include <set>

void make_permutation(std::string str, int l, int r, std::set<std::string> &set)
{
    if (l == r)
        set.insert(str);

    for (int i = l; i <= r; ++i)
    {
        std::swap(str[i], str[l]);

        make_permutation(str, l + 1, r, set);

        std::swap(str[i], str[l]);
    }
}

int main()
{
    std::string str = "racecar";

    std::set<std::string> set;
    make_permutation(str, 0, str.size() - 1, set);

    // for (auto &i : set)
    //     std::cout << i << std::endl;

    std::cout << set.size() << std::endl;

    return 0;
}