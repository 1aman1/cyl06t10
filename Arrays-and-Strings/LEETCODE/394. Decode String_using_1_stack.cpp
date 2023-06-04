#include <iostream>
#include <stack>

class Solution
{
public:
    std::string decodeString(std::string s)
    {

        // for everything other than
        std::stack<char> myStack;

        // auxillary string holders

        std::string resultStr = "";

        // traverse the complete string character by character
        for (int i = 0; i < s.length(); ++i)
        {
            // until closing bracket comes, push characters
            if (s[i] != ']')
            {
                myStack.push(s[i]);
            }

            else
            { // s[i] is ]
            
                std::string tempStr = "";
                while (!myStack.empty() && myStack.top() != '[')
                {
                    tempStr = myStack.top() + tempStr;
                    myStack.pop();
                }

                // currently s[i] is ] , pop it and after that fetch kth number
                myStack.pop();

                // prepare kNum
                std::string kChar;
                while (!myStack.empty() && isdigit(myStack.top()))
                {
                    kChar = myStack.top() + kChar;
                    myStack.pop();
                }

                // convert to integer
                int kNum = stoi(kChar);

                // // append string 'k' times
                std::string repeatedString;
                while (kNum)
                {
                    repeatedString += tempStr;
                    kNum--;
                }

                // push repeatedString to stack, character by character
                for (int i = 0; i < repeatedString.length(); ++i)
                {
                    myStack.push(repeatedString[i]);
                }
            }
        }

        // empty the myStack, make it a string before returning.
        while (!myStack.empty())
        {
            resultStr = myStack.top() + resultStr;
            myStack.pop();
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