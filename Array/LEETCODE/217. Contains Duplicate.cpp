class Solution
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::map<int, int> lookup;

        for (auto itr = nums.cbegin(); itr != nums.cend(); ++itr)
        {
            if (lookup.find(*itr) != lookup.end())
            {
                return true;
            }
            lookup.insert({*itr, 1});
        }
        return false;
    }
};