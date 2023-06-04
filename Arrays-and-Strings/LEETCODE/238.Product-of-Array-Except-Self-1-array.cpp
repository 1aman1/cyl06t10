#include <iostream>
#include <vector>
#include <ctime>

class Solution
{
private:
    int RangeForRandom = 5;
    int SequenceSize = 6;

public:
    Solution() { initArray(); }
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
    for (auto i : array)
        std::cout << i << " ";
    std::cout << std::endl;
}

std::vector<int> Solution::productExceptSelf()
{
    int size = array.size();
    int product_until_i;

    std::vector<int> result(size, 0);

    product_until_i = 1;
    for (int i = 0; i < size; ++i)
    {
        result[i] = product_until_i;
        product_until_i *= array[i];
    }

    product_until_i = 1;
    for (int i = size - 1; i >= 0; --i)
    {
        result[i] *= product_until_i;
        product_until_i *= array[i];
    }

    return result;
}

int main(int argc, char **argv)
{
    Solution obj;

    obj.print();

    for (const auto &i : obj.productExceptSelf())
        std::cout << i << " ";

    return 0;
}