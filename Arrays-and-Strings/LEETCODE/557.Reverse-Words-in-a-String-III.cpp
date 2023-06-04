
#include <iostream>
#include <algorithm>

class Solution
{
public:
    std::string reverseWords(std::string str)
    {
        int i, j, str_len;

        i = j = 0;
        str_len = str.length();

        while (i < str_len)
        {
            while (i < j || (i < str_len && str[i] == ' '))
                ++i;
            while (j < i || (j < str_len && str[j] != ' '))
                ++j;
            std::reverse(begin(str) + i, begin(str) + j);
        }

        return str;
    }
};

int main()
{
    std::string str = "Let's take LeetCode contest";

    Solution obj;

    std::cout << obj.reverseWords(str);
    
    return 0;
}