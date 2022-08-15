#include <iostream>
#include <map>

class Solution
{
public:
    std::map<int, bool> lookup;
    bool isHappy(int n)
    {
        int sqSum = 0, d1 = 0;

        while (n)
        {
            d1 = n % 10;
            sqSum += d1 * d1;
            n /= 10;
        }

        if (sqSum == 1)
            return true;

        if (lookup.count(sqSum))
            return false;
        else
        {

            lookup.insert({sqSum, true});

            return isHappy(sqSum);
        }
    }
};

int main()
{
    Solution obj;

    std::cout << std::boolalpha << obj.isHappy(2);

    return 0;
}