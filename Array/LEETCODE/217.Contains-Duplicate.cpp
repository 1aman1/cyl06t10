class Solution
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::set<int> lookup;

        for (auto itr = nums.begin(); itr != nums.end(); ++itr)
        {
            if (lookup.find(*itr) != lookup.end())
                return true;

            lookup.insert(*itr);
        }
        
        return false;
    }
};