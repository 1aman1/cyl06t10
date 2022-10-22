class Solution
{
public:
    map<string, vector<string>> cache;

    void build_cache(map<string, vector<string>> &cache, vector<string> &strings)
    {
        for (size_t i = 0; i < strings.size(); ++i)
        {
            string curr_str = strings[i];
            std::sort(strings[i].begin(), strings[i].end());

            if (!cache.count(strings[i]))
                cache.insert({strings[i], {curr_str}});
            else
                cache[strings[i]].push_back(curr_str);
        }
        // strings.resize(0);
    }

    vector<vector<string>> get_grouped_anagrams(const map<string, vector<string>> &cache)
    {
        vector<vector<string>> result;
        vector<string> sub_result;

        for (const auto &i : cache)
        {
            sub_result.resize(0);
            for (const auto &j : i.second)
                sub_result.push_back(j);
            result.push_back(sub_result);
        }
        return result;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        build_cache(cache, strs);

        vector<vector<string>> result = get_grouped_anagrams(cache);

        return result;
    }
};