#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &array, int target)
    {
        // store value with it's index
        std::unordered_map<int, int> lookup;
        for (int i = 0; i < array.size(); ++i)
        {
            int leftover = target - array[i];
            if (lookup.find(leftover) != lookup.end())
            {
                return {lookup.at(leftover) + 1, i + 1};
            }
            lookup.insert({array[i], i});
        }
        return {};
    }
};

int main(int argc, char **argv)
{
    Solution obj;

    int target = 9;
    vector<int> array = {2, 7, 11, 15};

    for (const auto &i : obj.twoSum(array, target))
        std::cout << i << " ";
    std::cout << "\n";

    return 0;
}
