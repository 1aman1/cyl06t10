#include <iostream>

bool oneReplace(std::string str1, std::string str2)
{
    bool onlyOneChar = false;
    for (int i = 0; i < str1.length(); ++i)
    {
        if (str1[i] != str2[i])
        {
            if (onlyOneChar == true) // already true, then this is the second time characters are different.
                return false;

            onlyOneChar = true;
        }
    }
    return true;
}

bool oneInsert(std::string str1, std::string str2)
{
    int index1 = 0;
    int index2 = 0;

    // iteration ends wrt to shorter string
    while (index1 < str1.length() && index2 < str2.length())
    {
        if (str1[index1] == str2[index2])
        {
            ++index1;
            ++index2;
        }
        else
        {
            if (index1 != index2)
                return false;
            ++index2;
        }
    }
    return true;
}

bool oneAway_1(std::string str1, std::string str2)
{
    if (str1.length() == str2.length())
    {
        return oneReplace(str1, str2);
    }
    else if (str1.length() - 1 == str2.length())
    {
        return oneInsert(str2, str1);
    }
    else
    {
        return oneInsert(str1, str2);
    }
}

bool oneAway_2(std::string str1, std::string str2)
{
    if (abs(str1.length() - str2.length()) > 1)
        return false;

    int index1 = 0;
    int index2 = 0;
    bool onlyOneChar = false;

    std::string s1 = str1.length() < str2.length() ? str1 : str2;
    std::string s2 = str1.length() < str2.length() ? str2 : str1;

    int s1Length = s1.length();
    int s2Length = s2.length();

    while (index1 < s1Length && index2 < s2Length)
    {
        if (s1[index1] != s2[index2])
        {
            // already true, then this is the second time characters are different.
            if (onlyOneChar == true)
                return false;

            onlyOneChar = true;
            // case for a replaced character
            if (s1Length == s2Length)
                ++index1;
        }
        else
        {
            ++index1;
        }

        ++index2;
    }

    return true;
}

int main()
{
    // INPUT SEC
    // std::string str1 = "pale";
    // std::string str2 = "ple";
    // std::string str1 = "bale";
    // std::string str2 = "bales";
    std::string str1 = "pale";
    std::string str2 = "bake";

    std::cout << std::boolalpha
              << oneAway_1(str1, str2) << std::endl
              << oneAway_2(str1, str2) << std::endl;

    return 0;
}