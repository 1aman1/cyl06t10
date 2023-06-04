class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        int local_maximum = 0;
        int resultant_maximum = INT_MIN;

        for (const auto &i : nums)
        {
            local_maximum = std::max(i, i + local_maximum);
            if (resultant_maximum < local_maximum)
                resultant_maximum = local_maximum;
        }
        return resultant_maximum;
    }
};
