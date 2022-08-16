#include <iostream>
#include <stack>

#define LOG true

class Quack
{
    std::stack<int> s1, s2, s3;

    template <typename T>
    void move(T &, T &);

public:
    void push(const int);
    int pop();
    int pull();

    void display(std::string);
};

template <typename T>
void Quack::move(T &source_stack, T &target_stack)
{
    while (!source_stack.empty())
    {
        target_stack.push(source_stack.top());
        source_stack.pop();
    }
}

void Quack::display(std::string s)
{
    if (s1.empty()) // s1 OR s2 are tightly synced
        std::cout << "STACK-EMPTY!\n";
        
    else
    {
        std::cout << s << " top : ";

        if (s == "s1")
            std::cout << s1.top();
        else
            std::cout << s2.top();

        std::cout << std::endl;
    }
}

void Quack::push(const int item)
{
    s1.push(item);

    move(s2, s3);

    s3.push(item);

    move(s3, s2);
}

int Quack::pop()
{
    if (s1.empty())
        return -1;

    // else
    int popped_item = s1.top();
    s1.pop();

    move(s2, s3);

    if (!s3.empty())
        s3.pop();

    move(s3, s2);

    return popped_item;
}

int Quack::pull()
{
    if (s1.empty())
        return -1;

    int popped_item = s2.top();
    s2.pop();

    move(s1, s3);

    if (!s3.empty())
        s3.pop();

    move(s3, s1);

    return popped_item;
}

int main()
{
    Quack quacko;

    quacko.push(1);
    quacko.push(2);

    quacko.display("s1");
    quacko.display("s2");

    quacko.push(3);
    quacko.display("s1");
    quacko.display("s2");

    std::cout << "pull " << quacko.pull() << std::endl;
    quacko.display("s1");
    quacko.display("s2");

    std::cout << "pop " << quacko.pop() << std::endl;
    quacko.display("s1");
    quacko.display("s2");

    quacko.push(4);
    quacko.display("s1");
    quacko.display("s2");

    std::cout << "pull " << quacko.pull() << std::endl;
    quacko.display("s1");
    quacko.display("s2");

    std::cout << "pull " << quacko.pull() << std::endl;
    quacko.display("s1");
    quacko.display("s2");

    std::cout << "pop " << quacko.pop() << std::endl;
    quacko.display("s1");
    quacko.display("s2");

    return 0;
}