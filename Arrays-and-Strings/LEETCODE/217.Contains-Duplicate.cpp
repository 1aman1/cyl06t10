class Solution
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::unordered_set<int> numCache;

        for (auto itr = nums.begin(); itr != nums.end(); ++itr)
        {
            if (numCache.count(*itr))
                return true;

            numCache.insert(*itr);
        }

        return false;
    }
};