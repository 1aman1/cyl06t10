class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        vector<int> frequency(26);

        for (const auto eachChar : s)
        {
            ++frequency[eachChar - 'a'];
        }

        for (const auto eachChar : t)
        {
            --frequency[eachChar - 'a'];
        }

        // examine
        for (const auto searchNaturalNumber : frequency)
            if (searchNaturalNumber != 0)
                return false;

        return true;
    }
};