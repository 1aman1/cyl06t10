class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int longest = 0;
        int length = s.length() - 1;

        map<char, int> lookup;

        int lhs = 0;
        for (int rhs = 0; rhs <= length; ++rhs)
        {
            // s[rhs];

            if (lookup.find(s[rhs]) != lookup.end())
            {
                // update left
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