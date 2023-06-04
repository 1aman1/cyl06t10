
#include <iostream>
#include <algorithm>

void generate_all_palindromes(std::string S)
{
    int size = S.size();
    if (size < 1)
        return;

    std::string reverseOfS;

    std::sort(S.begin(), S.end());
    do
    {
        reverseOfS = S;
        std::reverse(begin(reverseOfS), end(reverseOfS));

        if (S == reverseOfS)
            std::cout << S << "\n";

    } while (std::next_permutation(S.begin(), S.end()));
}

int main()
{
    std::string S = "ababaa";
    generate_all_palindromes(S);

    return 0;
}