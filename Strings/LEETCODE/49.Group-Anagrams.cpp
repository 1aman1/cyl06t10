class Solution
{
public:
    map<string, vector<string>> sortedToGroup;

    void
    build_cache(vector<string> &strings)
    {
        for (size_t i = 0; i < strings.size(); ++i)
        {
            string eachString = strings[i];
            sort(begin(eachString), end(eachString));

            if (!sortedToGroup.count(eachString))
                sortedToGroup.insert({eachString, {strings[i]}});
            else
                sortedToGroup[eachString].push_back(strings[i]);
        }
    }

    vector<vector<string>>
    groupAnagrams(vector<string> &strings)
    {
        build_cache(strings);

        vector<vector<string>> result;
        vector<string> subResult;

        for (auto [_, eachAnagram] : sortedToGroup)
        {
            for (const auto i : eachAnagram)
                subResult.push_back(i);
            result.push_back(subResult);
            subResult.resize(0);
        }

        return result;
    }
};