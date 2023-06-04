class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> slidingWindow;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (!slidingWindow.insert(nums[i]).second)
                return true;
            if (i >= k)
                slidingWindow.erase(nums[i - k]);
        }

        return false;
    }
};