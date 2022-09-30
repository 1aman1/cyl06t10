#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        for (int i = 0; i < nums.size(); ++i)
        {
            
        }
    }
};

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    Solution obj;

    cout << obj.pivotIndex(nums);
    cout << obj.pivotIndex(nums);
    cout << obj.pivotIndex(nums);
    return 0;
}