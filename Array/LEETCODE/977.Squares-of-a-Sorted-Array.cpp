#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int len = nums.size();

        vector<int> result(len);
        int resultOffset = len - 1;

        for (int left = 0, right = len - 1; left <= right;)
        {
            if (abs(nums[left]) > abs(nums[right]))
                result[resultOffset--] = nums[left] * nums[left++];
            else
                result[resultOffset--] = nums[right] * nums[right--];
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};

    Solution obj;

    for (const auto &i : nums)
        cout << i << " ";
    cout << "\n";

    obj.sortedSquares(nums);
    for (const auto &i : nums)
        cout << i << " ";

    cout << "\n";

    return 0;
}