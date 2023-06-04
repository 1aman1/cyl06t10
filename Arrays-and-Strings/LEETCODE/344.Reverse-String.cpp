#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void reverseString(std::vector<char> &s)
    {
        int l = 0;
        int r = s.size() - 1;

        while (l < r)
            swap(s[l++], s[r--]);
    }
};

int main()
{
    Solution obj;

    std::vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    obj.reverseString(s);
    
    std::cout << s << std::endl;

    return 0;
}