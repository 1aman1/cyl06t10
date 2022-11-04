#include <iostream>
#include <sstream>
/*
class test{};
*/

int countDigits(int num)
{
    // check if countConsecutive length is 0-9 or 10-99 or 100-999 so on
    std::string s = std::to_string(num);
    return s.size();
}

int afterCompressionLength(const std::string &str)
{
    int countConsecutive = 0;
    int compressedLength = 0;

    for (int i = 0; i < str.length(); ++i)
    {
        ++countConsecutive;
        if (str[i] != str[i + 1])
        {
            // increase length by character itself and it's frequency count length
            compressedLength += 1 + countDigits(countConsecutive);
            countConsecutive = 0;
        }
    }
    return compressedLength;
}

std::string string_compression(const std::string &str)
{
    // to avoid generating a string of no use
    if (str.length() <= afterCompressionLength(str))
        return str;

    int countConsecutive = 0;
    std::string compressedStr = "";
    for (int i = 0; i < str.length(); ++i)
    {
        ++countConsecutive;
        if (str[i] != str[i + 1])
        {
            compressedStr.push_back(str[i]);

            std::stringstream ss;
            ss << countConsecutive;
            compressedStr.append(ss.str());

            countConsecutive = 0;
        }
    }
    return compressedStr;
}

int main()
{
    std::string str1 = "aabcccccaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    std::string str2 = "aabbccd";

    str1 = string_compression(str2);
    std::cout << str1 << std::endl;

    return 0;
}