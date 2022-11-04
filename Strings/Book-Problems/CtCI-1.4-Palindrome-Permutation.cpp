#include <iostream>
#include <vector>
#include <iterator>

bool is_permutation_a_palindrome(std::string str)
{
    // read string , mark occurrence of it's characters
    std::vector<bool> freqOfStrCharacters(26, false);

    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] != ' ')
            freqOfStrCharacters[str[i] - 'a'] = !freqOfStrCharacters[str[i] - 'a'];
    }

    // for odd length, one odd element and rest even elements
    // for even length, all even elements
    int oddOccurrences = 0;
    for (auto itr = freqOfStrCharacters.begin(); itr != freqOfStrCharacters.end(); ++itr)
    {
        if (*itr == true)
            ++oddOccurrences;
    }

    // length is odd - only one charater would have odd count

    if (str.length() & 1)
    {
        if (oddOccurrences == 1)
            return true;
        else
            return false;
    }
    // length is even - no charaters would have odd count
    else
    {
        if (oddOccurrences == 0)
            return true;
        else
            return false;
    }
}

bool is_permutation_a_palindrome_BETA(std::string str)
{

    // REMOVES 2nd iteration for checking the odd occurrences as compared to function is_permutation_a_palindrome()

    // read string , mark frequency of it's characters
    std::vector<bool> freqOfStrCharacters(26, false);

    int oddOccurrences = 0;

    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == ' ')
            continue;
        ++oddOccurrences;
        if (freqOfStrCharacters[str[i] - 'a'] == true)
            oddOccurrences -= 2;

        if (str[i] != ' ')
            freqOfStrCharacters[str[i] - 'a'] = !freqOfStrCharacters[str[i] - 'a'];
    }

    // for odd length, one odd element and rest even elements
    // for even length, all even elements

    // length is odd - only one charater would have odd count
    if (str.length() & 1)
    {
        if (oddOccurrences == 1)
            return true;
        else
            return false;
    }
    // length is even - no charaters would have odd count
    else
    {
        if (oddOccurrences == 0)
            return true;
        else
            return false;
    }
}

int main()
{
    // INPUT SEC
    std::string str1 = "was it a car or a cat i saw";
    std::string str2 = "kayakr";

    std::cout << std::boolalpha
              << is_permutation_a_palindrome(str1) << std::endl
              << is_permutation_a_palindrome_BETA(str1) << std::endl

              << is_permutation_a_palindrome(str2) << std::endl
              << is_permutation_a_palindrome_BETA(str2) << std::endl

              << std::endl;

    return 0;
}