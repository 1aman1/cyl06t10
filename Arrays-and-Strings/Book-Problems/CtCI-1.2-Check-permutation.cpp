#include <iostream>
#include <algorithm>
#include <vector>
// using character frequency
bool is_permutation_1(std::string s1, std::string s2)
{
    if (s1.length() != s2.length())
        return false;

    std::vector<int> freq(26, 0);

    for (int i = 0; i < s1.length(); ++i)
        ++freq[s1[i] - 'a'];

    for (int i = 0; i < s2.length(); ++i)
        if (--freq[s2[i] - 'a'] < 0)
            return false;

    return true;
}

// using sort
bool is_permutation_2(std::string s1, std::string s2)
{
    if (s1.length() != s2.length())
        return false;

    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());

    if (s1 == s2)
        return true;
    else
        false;
}

int main()
{

    std::string str1 = "strings";
    std::string str2 = "gnistrs";

    std::cout << std::boolalpha
              << is_permutation_1(str1, str2)
              //   << is_permutation_2(str1, str2)
              << std::endl;

    return 0;
}