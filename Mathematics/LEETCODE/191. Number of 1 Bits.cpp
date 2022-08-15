#include <iostream>

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        return __builtin_popcount(n);
    }
};

int main()
{
    Solution o;
    std::cout << o.hammingWeight(404) << std::endl;
    return 0;
}