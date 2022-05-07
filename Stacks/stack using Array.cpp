#include <iostream>

class stack
{
private:
    int stackArr[20];
    int index;

public:
    stack() : index(-1)
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
    if (index < 0)
        return index;

    return stackArr[index];
}

bool stack::empty()
{
    if (index < 0)
        return true;

    return false;
}

int stack::size()
{
    return index + 1;
}

void stack::push(int data)
{
    ++index;
    stackArr[index] = data;
}

void stack::pop()
{
    if (!empty())
        --index;
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