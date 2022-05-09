#include <iostream>
#include <string>
#include <stack>

class Solution
{
public:
    std::string decodeString(std::string s)
    {
        std::string multiplyStr;
        std::string resStr;

        std::stack<int> kStack;
        std::stack<char> contextStack;
        // traverse the string char by char
        for (int i = 0; i < s.length(); ++i)
        {
            // when it is 'k'
            if (std::isdigit(s[i]))
            {
                kStack.push((int)s[i] - 48);

                // read next char
                continue;
            }

            // multiplier string starts
            if (s[i] == '[')
            {
                // contextStack.push(s[i]);
                ++i;
                while (s[i] != ']')
                {
                    multiplyStr = multiplyStr + s[i];
                    i++;
                }
                // contextStack.pop();

                int k = kStack.top();
                std::string tmpStr = multiplyStr;

                kStack.pop();
                k--;
                while (k > 0)
                {
                    multiplyStr += tmpStr;
                    k--;
                }

                resStr += multiplyStr;
                multiplyStr.resize(0);
            }
        }
        return resStr;
    }
};

int main()
{
    Solution obj;

    std::string s = "3[aB]2[pQ]";
    // invoke
    std::string result = obj.decodeString(s);

    // result should be aBaBaBpQpQ
    std::cout << result << std::endl;
    return 0;
}