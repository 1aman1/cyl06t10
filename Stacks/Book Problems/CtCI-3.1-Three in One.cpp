#include <iostream>
#include <vector>

/*
Idea is to implement stack in one array, by dividing array.size /NO_OF_STACKS
and the three different ranges we get, will be used to the NO_OF_STACKS stacks.

to see top of stack 1,  STACK_CAPACITY*Stack_ID + size -1
*/
#define ARRAY_LEN 10
#define NO_OF_STACKS 3
bool DEBUG = false;

class stackBase
{
public:
    stackBase()
    {
        stackSizes.resize(NO_OF_STACKS);
        std::fill(stackSizes.begin(), stackSizes.end(), 0);

        // making each stack equal size
        int size = ARRAY_LEN / NO_OF_STACKS;
        stackCapacity = size;

        size *= NO_OF_STACKS;
        values.resize(size);

        std::fill(values.begin(), values.end(), -1);
    };

    // complete array of values
    std::vector<int> values;

    // tracks the stack top
    std::vector<int> stackSizes;

    // max item count for each stack
    int stackCapacity;

    // methods
    void push(const int &stackId, const int element);

    void pop(const int &stackId);

    int peek(const int &);

    bool isEmpty(const int &stackId);

    bool isFull(const int &stackId);

    // utility
    int get_IndexOfTop(const int &stackId);
};

void stackBase::pop(const int &stackId)
{
    if (isEmpty(stackId))
    {
        return;
    }

    int top = get_IndexOfTop(stackId);
    int element = values[top];

    values[top] = -1;

    --stackSizes[stackId];

    DEBUG == true ? std::cout << __PRETTY_FUNCTION__ << element << " EOFn" << std::endl : std::cout << "";
}

int stackBase::get_IndexOfTop(const int &stackId)
{
    int offset = stackCapacity * stackId;
    int size = stackSizes[stackId];

    DEBUG == true ? std::cout << __PRETTY_FUNCTION__ << " " << stackId << std::endl : std::cout << "";

    return offset + size - 1;
}

// takes ID to distinguish, which stack to operate
void stackBase::push(const int &stackId, const int element)
{
    if (isFull(stackId))
    {
        DEBUG == true ? std::cout << __PRETTY_FUNCTION__ << " returned" << std::endl : std::cout << "";
        return;
    }

    ++stackSizes[stackId];
    values[get_IndexOfTop(stackId)] = element;

    DEBUG == true ? std::cout << __PRETTY_FUNCTION__ << " EOFn for stack" << stackId + 1 << std::endl : std::cout << "";
}

int stackBase::peek(const int &stackId)
{
    return values[get_IndexOfTop(stackId)];
}

bool stackBase::isEmpty(const int &stackId)
{
    return stackSizes[stackId] == 0;
}

bool stackBase::isFull(const int &stackId)
{
    return stackSizes[stackId] == stackCapacity;
}

int main(int argc, char **argv)
{

    stackBase obj;

    if (argc == 2)
    {
        if ("true" == static_cast<std::string>(*(argv + 1)))
            DEBUG = true;
    }

    std::cout << obj.get_IndexOfTop(0) << std::endl;
    std::cout << obj.get_IndexOfTop(1) << std::endl;
    std::cout << obj.get_IndexOfTop(2) << std::endl;

    obj.push(0, 100);
    obj.push(0, 200);
    obj.push(0, 300);
    obj.push(0, 400);

    obj.push(1, 500);
    obj.push(1, 600);
    obj.push(1, 700);
    obj.push(1, 800);

    obj.push(2, 900);
    obj.push(2, 1000);
    obj.push(2, 1100);
    obj.push(2, 1200);

    std::cout << obj.get_IndexOfTop(0) << std::endl;
    std::cout << obj.get_IndexOfTop(1) << std::endl;
    std::cout << obj.get_IndexOfTop(2) << std::endl;

    for (const auto &i : obj.values)
        std::cout << i << " ";
    std::cout << std::endl;

    obj.pop(2);

    std::cout << obj.peek(2) << std::endl;

    for (const auto &i : obj.values)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}