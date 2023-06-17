class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;

        int SIZE = nums.size();
        if (SIZE < 3)
            return result;

        sort(begin(nums), end(nums));

        for (int first = 0; first < SIZE - 2; ++first)
        {
            if (nums[first] > 0)
                break;

            if (first > 0 && nums[first] == nums[first - 1])
                continue;

            int left = first + 1;
            int right = SIZE - 1;

            while (left < right)
            {
                int sum = nums[first] + nums[left] + nums[right];

                if (sum < 0)
                {
                    ++left;
                }
                else if (sum > 0)
                {
                    --right;
                }
                else
                {
                    result.push_back({nums[first], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        ++left;
                    while (left < right && nums[right] == nums[right - 1])
                        --right;

                    ++left;
                    --right;
                }
            }
        }

        return result;
    }
};
