#include <iostream>
#include <vector>

class stack
{

private:
    std::vector<int> stackVec;

public:
    stack()
    {
    }

    int top();
    bool empty();
    int size();

    // modifiers
    void push(int);
    void pop();
};

int stack::top()
{
    if (stackVec.empty())
        return -1;

    return stackVec.back();
}

bool stack::empty()
{
    if (stackVec.empty())
        return true;

    return false;
}

int stack::size()
{
    return stackVec.size();
}

void stack::push(int data)
{
    stackVec.push_back(data);
}

void stack::pop()
{
    if (!stackVec.empty())
        stackVec.pop_back();
}

int main()
{
    stack mystack;

    int choice = 1, input;
    std::cout << "\n"
              << "1: top "
              << "2: push "
              << "3: pop "
              << "4: empty "
              << "5: size \n";

    while (choice)
    {

        std::cin >> input;

        switch (input)
        {

        case 1:
        {
            std::cout << "\ndata on top :"
                      << mystack.top()
                      << "\n";
            break;
        }

        case 2:
        {
            int value;
            std::cout << "\nPUSH : ";
            std::cin >> value;
            mystack.push(value);
            std::cout << "\n";
            break;
        }

        case 3:
        {
            mystack.pop();
            std::cout << "\n";
            break;
        }

        case 4:
        {
            std::cout << "\n is Empty : "
                      << std::boolalpha
                      << mystack.empty()
                      << "\n";
            break;
        }

        case 5:
        {
            std::cout << "\nsize :"
                      << mystack.size()
                      << "\n";
        }
        }

        std::cout << "continue ? ";
        std::cin >> choice;
    }

    return 0;
}