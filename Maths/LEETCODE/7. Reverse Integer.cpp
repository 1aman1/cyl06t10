#include <iostream>
#include <limits.h>

class Solution
{
public:
    int reverse(int x)
    {
        int reversedNumber = 0;

        /*
        INT_MAX is +2147483647
        INT_MIN is -2147483648.
        */

        while (x != 0)
        {
            int rem = x % 10;
            x /= 10;

            //                                                                  && VALID RANGE (0,7)
            if (reversedNumber > INT_MAX / 10 || reversedNumber == INT_MAX / 10 && rem > 7)
            {
                return 0;
            }

            //                                                                  && VALID RANGE (-8,0)
            if (reversedNumber < INT_MIN / 10 || reversedNumber == INT_MIN / 10 && rem < -8)
            {
                return 0;
            }

            reversedNumber = reversedNumber * 10 + rem;
        }

        return reversedNumber;
    }
};

int main()
{

    Solution obj;

    std::cout << "reversedNumber \n"
              << obj.reverse(-403)
              << std::endl;

    return 0;
}