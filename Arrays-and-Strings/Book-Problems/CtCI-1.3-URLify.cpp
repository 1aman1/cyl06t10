#include <iostream>

std::string
URLify(std::string Str, int trueLength)
{
    int spaceCount = 0;

    // count string for ' ' spaces
    for (int i = 0; i < trueLength; ++i)
    {
        if (Str[i] == ' ')
            ++spaceCount;
    }

    int fillerIndex = trueLength - spaceCount + spaceCount * 3 - 1;

    for (int i = trueLength - 1; i >= 0; --i)
    {
        if (Str[i] == ' ')
        {
            Str[fillerIndex - 0] = '0';
            Str[fillerIndex - 1] = '2';
            Str[fillerIndex - 2] = '%';
            fillerIndex -= 3;
        }
        else
            Str[fillerIndex--] = Str[i];
    }

    return Str;
}

int main()
{
    std::string str1 = "Mr John Smith    ";
    int trueLength = 13;

    std::cout << std::boolalpha
              << URLify(str1, trueLength)
              << std::endl;

    return 0;
}