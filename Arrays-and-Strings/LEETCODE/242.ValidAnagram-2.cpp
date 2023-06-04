class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> sCache;
        unordered_map<char, int> tCache;

        for (int i = 0; i < s.size(); ++i)
        {
            ++sCache[s[i]];
            ++tCache[t[i]];
        }

        // examine
        for (int i = 0; i < sCache.size(); ++i)
        {
            if (sCache[i] != tCache[i])
                return false;
        }

        return true;
    }
};