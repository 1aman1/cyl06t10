#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        const int SIZE = nums.size();
        int last_non_zero = 0;

        for (int i = 0; i < SIZE; ++i)
        {
            if (nums[i] != 0)
                nums[last_non_zero++] = nums[i];
        }

        while (last_non_zero < SIZE)
            nums[last_non_zero++] = 0;
    }
};

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};

    Solution obj;
    obj.moveZeroes(nums);

    for (auto i : nums)
        cout << i << "\n";
    return 0;
}