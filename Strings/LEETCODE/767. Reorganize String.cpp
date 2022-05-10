#include <iostream>
#include <algorithm>

#define DEBUG true

class Solution
{
public:
    std::string reorganizeString(std::string s)
    {
        // check all permutations,
        // solution needs atleast one string possible,
        // if NONE, return "", empty string.

        // std::string resStr = s;
        std::sort(s.begin(), s.end());

        bool hasAdjacentSameCharacters = false;
        do
        { // for each permutation, test adjacent values to be different
            DEBUG == true ? std::cout << "NEW STRING " << s << std::endl : std::cout << "";

            for (int i = 0; i < s.length() - 1; ++i)
            {
                {
                    DEBUG == true ? std::cout << s[i] << "-" << s[i + 1] << std::endl : std::cout << "";
                    //  if not same, keep checking till end
                    if (s[i] != s[i + 1])
                    {
                        DEBUG == true ? std::cout << "CHECK" << std::endl : std::cout << "";
                        hasAdjacentSameCharacters = false;
                        continue;
                    }
                    else
                    {
                        DEBUG == true ? std::cout << "REJECTED" << std::endl : std::cout << "";
                        //  if the string has adjacent same characters atleast one time
                        //  then this permutation doesn't qualify
                        hasAdjacentSameCharacters = true;
                        break;
                        // and test the next permutation
                    }
                }
            }

        } while (hasAdjacentSameCharacters && std::next_permutation(s.begin(), s.end()));

        if (hasAdjacentSameCharacters == false)
            return s;
        else
            return "";
    }
};

int main()
{
    Solution obj;
    std::string s = "aab";

    std::string res = obj.reorganizeString(s);

    std::cout << "Result :" << res << std::endl;

    return 0;
}