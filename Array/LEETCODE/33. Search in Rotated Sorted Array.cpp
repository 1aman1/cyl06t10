#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        // find to see if the element is present in the sequence or not
        auto searchResult = std::find(nums.begin(), nums.end(), target);

        //  iterator to end is returned if item not found
        if (searchResult == nums.end())
            return -1;
        else
        {
            // distance gives the INT difference in two iterators
            return std::distance(nums.begin(), searchResult);
        }
    }
};

int main()
{
    std::vector<int> vec = {4, 5, 6, 7, 0, 1, 2};
    Solution obj;

    std::cout << obj.search(vec, 0)
              << std::endl;

    return 0;
}