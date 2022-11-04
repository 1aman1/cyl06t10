
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

struct Wordo
{
    string word;
    int freq;

    Wordo(string word, int freq) : word(word), freq(freq){};
};

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> wordToFreq;

        for (const auto &eachWord : words)
            ++wordToFreq[eachWord];

        auto custom_compare = [](const Wordo &lhs, const Wordo &rhs)
        { return lhs.freq == rhs.freq ? lhs.word < rhs.word : lhs.freq > rhs.freq; };

        priority_queue<Wordo, vector<Wordo>, decltype(custom_compare)>
            heap(custom_compare);

        for (const auto i : wordToFreq)
        {
            heap.emplace(i.first, i.second);
            if (heap.size() > k)
                heap.pop();
        }

        vector<string> result;
        while (!heap.empty())
            result.insert(begin(result), (heap.top().word)), heap.pop();

        return result;
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