#include <iostream>
#include <vector>

class Solution
{
public:
    void reverseString(std::vector<char> &s)
    {
        int len = s.size();
        for (int i = 0; i < len / 2; ++i)
        {
            char tmp = s[i];
            s[i] = s[len - 1 - i];
            s[len - 1 - i] = tmp;
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