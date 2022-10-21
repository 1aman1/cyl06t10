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
        int left = 0;
        int right = array.size() - 1;

        while (array[left] + array[right] != target)
        {
            if (array[left] + array[right] > target)
                --right;
            else
                ++left;
        }
        return {left + 1, right + 1};
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
