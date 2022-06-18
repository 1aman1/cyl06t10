#include <iostream>

class Solution
{
public:
    int strStr(std::string haystack, std::string needle)
    {
        int hayStackSize = haystack.size();
        int needleSize = needle.size();

        if (needleSize == 0 || needleSize > hayStackSize)
            return -1;
        else
        {
            return (haystack.find(needle) == std::string::npos) ? -1
                                                                : haystack.find(needle);
        }
    }
};

int main()
{
    std::string haystack = "hello";
    std::string needle = "ll";

    Solution obj;
    std::cout << obj.strStr(haystack, needle)
              << std::endl;

    return 0;
}