#include <iostream>
#include <vector>

class Solution
{
public:
    void reverseString(std::vector<char> &s)
    {
        int len = s.size() - 1;
        for (int i = 0; i <= len / 2; ++i)
        {
            if (s[i] != s[len - i])
            {
                char tmp = s[i];
                s[i] = s[len - i];
                s[len - i] = tmp;
            }
        }
    }
};

int main()
{
    Solution obj;

    std::vector<char> s = [ 'h', 'e', 'l', 'l', 'o' ];

    obj.reverseString(s);
    std::cout << str << std::endl;

    return 0;
}