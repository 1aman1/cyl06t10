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

class QusingStack : public debugUtil
{
    // used for peek_back
    int last_push = -1;

public:
    std::stack<int> inStack;
    std::stack<int> outStack;

    void push(int);
    void pop();

    void shiftStack();

    int front();

    int back();
    int back_var();

    int size();
    bool empty();
};

void QusingStack::shiftStack()
{
    if (outStack.empty())
        while (!inStack.empty())
        {
            outStack.push(inStack.top());
            inStack.pop();
        }
}

void QusingStack::push(int element)
{
    inStack.push(element);
    last_push = element;

    ifDEBUGLOG() == true ? std::cout << "inserted: " << element << std::endl : std::cout << "";
}

void QusingStack::pop()
{
    if (size() == 0)
    {
        ifDEBUGLOG() == true ? std::cout << "queue empty" << std::endl : std::cout << "";
        return;
    }

    shiftStack();

    ifDEBUGLOG() == true ? std::cout << "popping: " << outStack.top() << std::endl : std::cout << "";

    outStack.pop();
}

int QusingStack::front()
{
    if (size() == 0)
    {
        ifDEBUGLOG() == true ? std::cout << "queue empty" << std::endl : std::cout << "";
        return -1;
    }

    shiftStack();

    ifDEBUGLOG() == true ? std::cout << "FRONT: " << outStack.top() << std::endl : std::cout << "";

    return outStack.top();
}

int QusingStack::back()
{
    if (size() == 0)
    {
        ifDEBUGLOG() == true ? std::cout << "queue empty" << std::endl : std::cout << "";
        return -1;
    }

    if (!outStack.empty())
    {
        while (!outStack.empty())
        {
            inStack.push(outStack.top());
            outStack.pop();
        }
    }

    ifDEBUGLOG() == true ? std::cout << "BACK: " << inStack.top() << std::endl : std::cout << "";

    return inStack.top();
}

// beta, without inverting complete stack, we can maintain a last pushed element variable
int QusingStack::back_var()
{
    if (size() == 0)
    {
        ifDEBUGLOG() == true ? std::cout << "queue empty" << std::endl : std::cout << "";

        // beta
        last_push = -1;
        return -1;
    }

    ifDEBUGLOG() == true ? std::cout << "BACK: " << last_push << std::endl : std::cout << "";

    return last_push;
}

int QusingStack::size()
{
    return inStack.size() + outStack.size();
}

bool QusingStack::empty()
{
    return (size() == 0);
}

int main(int argc, char **argv)
{
    QusingStack obj;

    if (argc == 2)
    {
        if ("true" == static_cast<std::string>(*(argv + 1)))
            obj.setDebugTrue();
    }

    obj.pop();

    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);

    obj.pop();
    obj.front();
    // obj.back();
    obj.back_var();

    obj.pop();
    obj.front();
    // obj.back();
    obj.back_var();

    std::cout << std::boolalpha << "is empty " << obj.empty() << std::endl;

    obj.push(5);
    obj.front();
    // obj.back();
    obj.back_var();

    // tests
    // obj.push(1);
    // obj.push(2);
    // obj.push(3);

    // std::cout << obj.front() << std::endl;

    // obj.pop();
    // std::cout << obj.front() << std::endl;

    // obj.pop();
    // std::cout << obj.front() << std::endl;

    // // obj.pop();
    // // std::cout << obj.front() << std::endl;

    // obj.push(4);
    // std::cout << obj.front() << std::endl;

    // obj.push(5);
    // std::cout << obj.front() << std::endl;

    // // obj.push(6);
    // // std::cout << obj.front() << std::endl;

    // obj.pop();
    // std::cout << obj.front() << std::endl;

    return 0;
}