class Solution
{
public:
    bool isValid(string s)

    {
        std::stack<char> myStack;
        char currChar;

        for (long unsigned int i = 0; i < s.length(); ++i)
        {
            // store to validate further
            currChar = s[i];

            // validate
            if (currChar == '(' || currChar == ')' || currChar == '[' || currChar == ']' || currChar == '{' || currChar == '}')
            {
                // if opening bracket
                if (currChar == '(' || currChar == '[' || currChar == '{')
                {
                    myStack.push(currChar);
                    continue;
                }

                // when closing bracket appears first
                if (myStack.size() == 0)
                {
                    return false;
                }

                // if closing bracket, then validate it with most recent bracket

                char top = myStack.top();

                // match the closing brackets properly
                if ((currChar == ')' && top == '(') || (currChar == '}' && top == '{') || (currChar == ']' && top == '['))
                    myStack.pop();
                else
                    break;
            }

            // skip validation when the current charater is a bracket
            continue;
        }
        if (myStack.size() == 0)
            return true;
        else
            return false;
    }
};