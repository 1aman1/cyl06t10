class Solution
{
public:
    bool isValid(string s)
    {
        std::stack<char> myStack;

        for (const char current : s)
        {
            if (current == '(' || current == '[' || current == '{')
            {
                myStack.push(current);
                continue;
            }

            if (myStack.size() == 0) // when closing bracket appears first
                return false;

            char top = myStack.top();

            // match the closing brackets properly
            if ((current == ')' && top == '(') || (current == '}' && top == '{') || (current == ']' && top == '['))
                myStack.pop();
            else
                break;
        }

        return myStack.empty();
    }
};