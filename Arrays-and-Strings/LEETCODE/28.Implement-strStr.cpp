#include <iostream>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        const int haySize = haystack.length();
        const int needleSize = needle.length();

        for (int i = 0; i < haySize - needleSize + 1; i++)
            if (haystack.substr(i, needleSize) == needle)
                return i;

        return -1;
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