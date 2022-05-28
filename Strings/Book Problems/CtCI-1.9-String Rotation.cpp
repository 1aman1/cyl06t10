#include <iostream>

bool string_rotation(std::string s1, std::string s2)
{
    if (s1.length() == s2.length() && s1.length() > 0)
    {
        s1 = s1 + s1;

        return (s1.find(s2) != std::string::npos);
    }
    return false;
}

int main()
{
    std::string s1 = "waterbottle";
    std::string s2 = "erbottlewat";
    std::cout << std::boolalpha
              << string_rotation(s1, s2)
              << std::endl;
    return 0;
}
