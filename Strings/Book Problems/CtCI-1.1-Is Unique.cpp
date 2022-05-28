#include <iostream>

// map
bool isUnique_1(std::string str)
{
    int *arr = new int[str.length() - 1];

    for (int i = 0; i < str.length(); ++i)
    {
        int val = str[i];
        if (arr[val])
            return false;
        else
            arr[val] = true;
    }

    return true;
}

// bit
bool isUnique_2(std::string str)
{
    int checker = 0;

    for (int i = 0; i < str.length(); ++i)
    {
        int val = str[i] - 'a';
        if (checker & (1 << val) > 0)
        {
            return false;
        }
        checker |= (1 << val);
    }
    return true;
}

int main()
{
    std::string str1 = "aman";
    std::string str2 = "gupta";

    std::cout << std::boolalpha << isUnique_1(str1) << std::endl;
    std::cout << std::boolalpha << isUnique_2(str1) << std::endl;

    std::cout << std::boolalpha << isUnique_1(str2) << std::endl;
    std::cout << std::boolalpha << isUnique_2(str2) << std::endl;

    return 0;
}
