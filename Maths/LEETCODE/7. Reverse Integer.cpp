#include <iostream>
#include <string>
#include <limits.h>
#define DEBUG false

/*

Dividing MAX_VALUE by 10 lets you check the condition without overflowing

INT_MAX is equal 2147483647. INT_MIN is equal  -2147483648.

Last digits are 7 and 8. This is the reason why we also  check  rem > 7 and rem < -8 conditions

*/

class Solution
{
public:
    int reverse(int num)
    {
        int reversedNumber = 0;

        while (num != 0)
        {
            int rem = num % 10;
            num /= 10;

            //                                                                     RANGE (0,7)
            if (reversedNumber > INT_MAX / 10 || reversedNumber == INT_MAX / 10 && rem > 7)
            {
                return 0;
            }
            //                                                                     RANGE (-8,0)
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