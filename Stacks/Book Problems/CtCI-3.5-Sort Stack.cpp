#include <iostream>
#include <stack>

class debugUtil
{
    bool DEBUGLOG = false;

public:
    debugUtil(){};

    void setDebugTrue()
    {
        DEBUGLOG = true;
    }

    bool ifDEBUGLOG()
    {
        return DEBUGLOG;
    }
};

class Solution : public debugUtil
{
public:
    std::stack<int> myStack;

    void push(int);
    void pop();
    int top();
    void sort();
};

int Solution::top()
{
    return myStack.top();
}

void Solution::push(int element)
{
    // this is needed later to trigger sorting if 'element' is bigger

    // int lastTop = -1;

    // if (myStack.size() > 0)
    //     lastTop = myStack.top();

    int lastTop = myStack.size() > 0 ? myStack.top() : -1;
    myStack.push(element);

    ifDEBUGLOG() == true ? std::cout << "inserted: " << element << std::endl : std::cout << "";

    if (element > lastTop)
    {
        sort();
        ifDEBUGLOG() == true ? std::cout << "sorted" << std::endl : std::cout << "";
    }
}

void Solution::sort()
{
    std::stack<int> auxStack;

    while (!myStack.empty())
    {
        int tmp = myStack.top();
        myStack.pop();

        while (!auxStack.empty() && tmp < auxStack.top())
        {
            myStack.push(auxStack.top());
            auxStack.pop();
        }

        auxStack.push(tmp);
    }

    // get elements back to main stack
    while (!auxStack.empty())
    {
        myStack.push(auxStack.top());
        auxStack.pop();
    }
}

void Solution::pop()
{
    if (myStack.size() == 0)
    {
        ifDEBUGLOG() == true ? std::cout << "queue empty" << std::endl : std::cout << "";
        return;
    }

    ifDEBUGLOG() == true ? std::cout << "popping: " << myStack.top() << std::endl : std::cout << "";

    myStack.pop();
}

int main(int argc, char **argv)
{
    Solution obj;

    if (argc == 2)
    {
        if ("true" == static_cast<std::string>(*(argv + 1)))
            obj.setDebugTrue();
    }

    obj.push(12);
    obj.push(10);
    obj.push(1);
    obj.push(2);
    obj.push(20);

    // obj.sort();

    std::cout << obj.top() << std::endl;
    obj.pop();

    std::cout << obj.top() << std::endl;
    obj.pop();

    std::cout << obj.top() << std::endl;
    obj.pop();

    std::cout << obj.top() << std::endl;
    obj.pop();

    std::cout << obj.top() << std::endl;
    // expected 1 2 10 12

    return 0;
}