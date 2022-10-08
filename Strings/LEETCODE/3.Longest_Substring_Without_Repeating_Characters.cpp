class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> lookup;

        int lhs = 0;
        int longest = 0;
        for (int rhs = 0; rhs < s.length(); ++rhs)
        {
            if (lookup.find(s[rhs]) != lookup.end())
            {
                lhs = std::max(lhs,
                               lookup[s[rhs]] + 1);
            }

            lookup[s[rhs]] = rhs;
            longest = std::max(longest,
                               rhs - lhs + 1);
        }

        return longest;
    }
};