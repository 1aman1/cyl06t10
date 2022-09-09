
// string
// all possible palindromes

#include <iostream>
#include <algorithm>

bool is_string_palin(const std::string &s, const int &size)
{
    for (int i = 0; i < size / 2; ++i)
    {
        if (s[i] != s[size - i - 1])
        {
            return false;
        }
    }
    return true;
}

void get_all_palins(std::string s)
{
    int size = s.size();

    std::sort(s.begin(), s.end());
    do
    {
        if (is_string_palin(s, size))
            std::cout << ": " << s << "\n";

    } while (std::next_permutation(s.begin(), s.end()));
}

int main()
{
    std::string s = "ababaa";
    get_all_palins(s);

    return 0;
}