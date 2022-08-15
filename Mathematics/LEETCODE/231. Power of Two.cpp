#include <iostream>

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        return ((n & (n - 1)) == 0);
    }
};

int main()
{

    Solution o;
    std::cout << std::boolalpha << o.isPowerOfTwo(17) << std::endl;
    return 0;
}