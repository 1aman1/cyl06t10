#include <iostream>
#include <vector>

class queue
{
private:
    std::vector<int> qVec;

public:
    queue()
    {
        qVec.reserve(20);
    }

    bool empty();
    int size();

    int front();
    int back();

    void push(int);
    void pop();
};

bool queue::empty()
{
    if (qVec.empty())
        return true;

    return false;
}

int queue::size()
{
    return qVec.size();
}

int queue::front()
{
    if (qVec.size() < 0)
        return -1;

    return qVec.front();
}

int queue::back()
{
    if (qVec.size() < 0)
        return -1;

    return qVec.back();
}

void queue::push(int data)
{
    qVec.push_back(data);
}

void queue::pop()
{
    if (qVec.size() < 0)
        return;

    qVec.erase(qVec.begin());
}

int main()
{

    queue myQ;
    int choice = 1, input;

    std::cout << "\n"
              << " 1: front  "
              << " 2: back  "
              << " 3: push  "
              << " 4: pop   "
              << " 5: size   "
              << " 6: empty  ---> ";

    while (choice)
    {

        std::cin >> input;

        switch (input)
        {

        case 1:
        {
            std::cout << "element on front : "
                      << myQ.front()
                      << "\n";
            break;
        }

        case 2:
        {
            std::cout << "element on back : "
                      << myQ.back()
                      << "\n";
            break;
        }

        case 3:
        {
            int value;
            std::cin >> value;
            myQ.push(value);
            std::cout << "\n";
            break;
        }

        case 4:
        {
            myQ.pop();
            std::cout << "\n";
            break;
        }

        case 5:
        {
            std::cout << "\nsize :"
                      << myQ.size()
                      << "\n";
            break;
        }

        case 6:
        {
            std::cout << "\nis empty :"
                      << std::boolalpha
                      << myQ.empty()
                      << "\n";
            break;
        }
        }

        std::cout << "continue ?";
        std::cin >> choice;
    }

    return 0;
}
