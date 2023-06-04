
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        const size_t SIZE = words.size();

        vector<string> result;
        vector<vector<string>> lookup(SIZE + 1);
        unordered_map<string, int> count;

        for (const auto eachWord : words)
            ++count[eachWord];

        for (const auto &[eachWord, freq] : count)
            lookup[freq].push_back(eachWord);

        for (int i = SIZE; i >= 0; --i)
        {
            sort(begin(lookup[i]), end(lookup[i]));

            for (const auto &eachWord : lookup[i])
            {
                result.push_back(eachWord);
                if (result.size() == k)
                    return result;
            }
        }

        return {""};
    }
};

int main()
{
    Solution obj;
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;

    obj.topKFrequent(words, k);

    return 0;
}