#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

class debugUtil
{
    bool DEBUGLOG;

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
    void print();

    const std::vector<int> twoSum_solution2(int);

    std::vector<int> array;
};

// O(n)
// Space(n)
// 29ms
const std::vector<int> Solution::twoSum_solution2(int item)
{
    // store value with it's index
    std::unordered_map<int, int> lookup;
    for (int i = 0; i < array.size(); ++i)
    {
        int leftover = item - array[i];
        if (lookup.find(leftover) != lookup.end())
        {
            return {lookup.at(leftover) + 1, i + 1};
        }
        lookup.insert({array[i], i});
    }
    return {};
}

void Solution::print()
{
    for (const auto &i : array)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    Solution obj;

    if (argc == 2)
    {
        if ("true" == static_cast<std::string>(*(argv + 1)))
            obj.setDebugTrue();
    }

    obj.array = {3, 2, 4};
    obj.print();

    std::cout << std::endl;
    for (const auto &i : obj.twoSum_solution2(6))
        std::cout << i << " ";

    return 0;
}
