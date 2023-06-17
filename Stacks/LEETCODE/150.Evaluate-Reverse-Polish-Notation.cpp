#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <bitset>
#include <list>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> myStack;

        for (int i = 0; i < tokens.size(); i++)
        {
            string token = tokens[i];

            if (token.size() > 1 || isdigit(token[0]))
            {
                myStack.push(stoi(token));
                continue;
            }

            int num2 = myStack.top();
            myStack.pop();
            int num1 = myStack.top();
            myStack.pop();

            int result = 0;
            if (token == "+")
            {
                result = num1 + num2;
            }
            else if (token == "-")
            {
                result = num1 - num2;
            }
            else if (token == "*")
            {
                result = num1 * num2;
            }
            else
            {
                result = num1 / num2;
            }
            myStack.push(result);
        }

        return myStack.top();
    }
};

int main()
{
    Solution obj;
    vector<string> seq = {"2", "1", "+", "3", "*"};

    obj.evalRPN(seq);
    return 0;
}