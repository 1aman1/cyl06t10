#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int size = nums.size();
        
        if (k >= size)
            k %= size;

        reverse(nums.begin(), nums.end());

        reverse(nums.begin(), nums.begin() + k);

        reverse(nums.begin() + k, nums.end());
    }
};

int main()
{

    // vector<int> nums = {-1, -100, 3, 99};
    vector<int> nums = {1, 2};
    // vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    Solution obj;

    for (auto i : nums)
        cout << i << " ";

    cout << "\n";
    obj.rotate(nums, 3);

    for (auto i : nums)
        cout << i << " ";

    return 0;
}