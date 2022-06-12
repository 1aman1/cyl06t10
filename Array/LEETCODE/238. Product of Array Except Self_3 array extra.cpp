#include <iostream>
#include <vector>
#include <ctime>

class debugUtil
{
    bool DEBUGLOG = false;

public:
    debugUtil(){
        // no object needed for this class
    };

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
private:
    int RangeForRandom = 5;
    int SequenceSize = 6;

public:
    void initArray();
    void print();
    std::vector<int> productExceptSelf();

private:
    std::vector<int> array;
};

void Solution::initArray()
{
    srand(time(nullptr));

    for (int i = 0; i < SequenceSize; i++)
    {
        array.push_back(1 + rand() % RangeForRandom);
    }
}

void Solution::print()
{
    ifDEBUGLOG() == true ? std::cout << "array:" << std::endl : std::cout << "";

    for (auto i : array)
        std::cout << i << " ";
    std::cout << std::endl;
}

std::vector<int> Solution::productExceptSelf()
{
    int length = array.size();

    std::vector<int> prefix(length, 0);
    std::vector<int> suffix(length, 0);

    // prepare suffix
    suffix[length - 1] = 1;
    for (int i = length - 2; i > -1; --i)
    {
        suffix[i] = suffix[i + 1] * array[i + 1];
    }

    // prepare prefix
    prefix[0] = 1;
    for (int i = 1; i < length; ++i)
    {
        prefix[i] = prefix[i - 1] * array[i - 1];
    }

    std::vector<int> output(length, 0);

    for (int i = 0; i < length; ++i)
    {
        output[i] = suffix[i] * prefix[i];
    }

    return output;
}

int main(int argc, char **argv)
{
    Solution obj;
    obj.initArray();

    if (argc == 2)
    {
        if ("true" == static_cast<std::string>(*(argv + 1)))
            obj.setDebugTrue();
    }

    obj.print();

    for (const auto &i : obj.productExceptSelf())
    {
        std::cout << i << " ";
    }

    // obj.print();
}
