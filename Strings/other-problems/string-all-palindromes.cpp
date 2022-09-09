// string
// all possible palindromes

#include <iostream>
#include <algorithm>

void all_palin(std::string s)
{
    int size = s.size();

    bool is_palin = false;

    std::sort(s.begin(), s.end());

    do
    {
        for (int i = 0; i < size / 2; ++i)
        {
            if (s[i] != s[size - i - 1])
            {
                is_palin = false;
                i = size;
                continue;
            }
            else
                is_palin = true;
        }

        if (is_palin)
            std::cout << ": " << s << "\n";

    } while (std::next_permutation(s.begin(), s.end()));
}

int main()
{
    std::string s = "ababaa";

    all_palin(s);

    return 0;
}