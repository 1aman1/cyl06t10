#include <iostream>
#include <string>
std::string URLify(std::string Str)
{
    for (int i = 0; i < Str.length(); ++i)
    {
        if (Str[i] == ' ')
        {
            Str = Str.substr(0, i) + "%20" + Str.substr(i + 1, Str.length());
        }
    }
    return Str;
}

int main()
{

    std::string str1 = "str in gs";
    std::string str2 = " gnistrs ";

    std::cout << std::boolalpha
              << URLify(str1) << std::endl
              << URLify(str2) << std::endl
              << std::endl;

    return 0;
}