#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Solution
{
private:
    static constexpr int RANDOMRANGE = 5;
    static constexpr int SIZE = 6;

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

    for (int i = 0; i < SIZE; i++)
    {
        array.push_back(1 + rand() % RANDOMRANGE);
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
    size_t size = array.size();

    vector<int> prefix(size, 0);
    vector<int> suffix(size, 0);

    prefix[0] = 1;
    for (int i = 1; i < size; ++i)
        prefix[i] = prefix[i - 1] * array[i - 1];

    suffix[size - 1] = 1;
    for (int i = size - 1 - 1; i >= 0; --i)
        suffix[i] = suffix[i + 1] * array[i + 1];

    for (int i = 0; i < size; ++i)
        array[i] = prefix[i] * suffix[i];

    return array;
}

int main(int argc, char **argv)
{
    Solution obj;

    obj.print();

    for (const auto &i : obj.productExceptSelf())
        std::cout << i << " ";

    return 0;
}
