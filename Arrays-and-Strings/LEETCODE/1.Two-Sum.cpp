#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

class Solution
{
public:
    void print();

    const std::vector<int> twoSum_solution1(int);

    const std::vector<int> twoSum_solution2(int);

    bool twoSum_solution3(int);

    bool twoSum_solution4(int);

    std::vector<int> array;
};

// O(n^2)
// Space(1)
// 520 ms
const std::vector<int> Solution::twoSum_solution1(int item)
{
    for (int i = 0; i < array.size(); ++i)
    {
        for (int j = i + 1; j < array.size(); ++j)
        {
            if (array[i] + array[j] == item)
                return {i, j};
        }
    }
    return {};
}

// O(n)
// Space(n)
// 19ms
const std::vector<int> Solution::twoSum_solution2(int item)
{
    // store value with it's index
    std::unordered_map<int, int> lookup;
    for (int i = 0; i < array.size(); ++i)
    {
        int leftover = item - array[i];
        if (lookup.find(leftover) != lookup.end())
        {
            return {lookup.at(leftover), i};
        }
        lookup.insert({array[i], i});
    }
    return {};
}

// O(n *log(n))
// Space(1)
bool Solution::twoSum_solution3(int item)
{
    std::sort(array.begin(), array.end());
    for (int left = 0, right = array.size() - 1; left < right;)
    {
        if (array[left] + array[right] == item)
            return true;
        else if (array[left] + array[right] < item)
            ++left;
        else
            right--;
    }

    return false;
}

// O(n)
// Space(n)
bool Solution::twoSum_solution4(int item)
{
    std::unordered_set<int> lookupMap;

    for (int i = 0; i < array.size(); ++i)
    {
        int leftover = item - array[i];

        if (lookupMap.find(leftover) != lookupMap.end())
            return true;
        lookupMap.insert(array[i]);
    }

    return false;
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

    obj.array = {3, 2, 4};
    obj.print();

    for (const auto &i : obj.twoSum_solution1(6))
        std::cout << i << " ";

    std::cout << std::endl;
    for (const auto &i : obj.twoSum_solution2(6))
        std::cout << i << " ";

    std::cout << std::endl;
    std::cout << std::boolalpha << obj.twoSum_solution3(6);

    std::cout << std::endl;
    std::cout << std::boolalpha << obj.twoSum_solution4(6);

    return 0;
}
