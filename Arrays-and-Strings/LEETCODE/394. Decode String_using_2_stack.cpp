#include <iostream>
#include <string>
#include <stack>

class Solution
{
public:
    std::string decodeString(std::string s)
    {

        // store multiplier number 'k'
        std::stack<int> kStack;

        // for everything other than 'k'
        std::stack<char> charStack;

        // auxillary string holders
        std::string tempStr = "";
        std::string resultStr = "";

        // traverse the complete string character by character
        for (int i = 0; i < s.length(); ++i)
        {
            // usage of 'k'
            int kNum = 0;

            // s[i] is a number
            if (s[i] >= '0' && s[i] <= '9')
            {
                // number can 1..300
                // form complete integer before pushing to stack

                while (s[i] >= '0' && s[i] <= '9')
                {
                    kNum = kNum * 10 + s[i] - '0';
                    i++;
                }

                kStack.push(kNum);

                // loop broke on a character, not a digit,
                // so drag i, one index back before further traversal
                i--;
            }

            // s[i] is [
            else if (s[i] == '[')
            {
                charStack.push(s[i]);
            }

            // s[i] is ]
            else if (s[i] == ']')
            {
                // idea is to fetch latest k number and take string out from stack for current bracket
                // ie, before [
                tempStr = "";
                kNum = 0;

                // fetch k num
                if (!kStack.empty())
                {
                    kNum = kStack.top();
                    kStack.pop();
                }

                // fetch the complete string before [
                while (!charStack.empty() && charStack.top() != '[')
                {
                    tempStr = charStack.top() + tempStr;
                    charStack.pop();
                }

                // once complete string is taken, pop the starter bracket also
                if (!charStack.empty() && charStack.top() == '[')
                    charStack.pop();

                // append string 'k' times
                while (kNum)
                {
                    resultStr = resultStr + tempStr;
                    kNum--;
                }

                // push resultString to stack, character by character
                for (int mux = 0; mux < resultStr.length(); mux++)
                    charStack.push(resultStr[mux]);

                resultStr = "";
            }

            else
            {
                charStack.push(s[i]);
            }
        }

        // empty the charStack, make it a string before returning.
        while (!charStack.empty())
        {
            resultStr = charStack.top() + resultStr;
            charStack.pop();
        }

        return resultStr;
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