#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution
{
public:
    int maxLength(vector<string> &arr)
    {
        vector<bitset<26>> array_char_bitcache = {bitset<26>()};
        int result = 0;

        for (auto &str : arr)
        {
            bitset<26> curr_char_bitcache;
            for (char c : str)
                curr_char_bitcache.set(c - 'a');
            int size = curr_char_bitcache.count();

            if (size < str.size())
                continue;

            for (int i = array_char_bitcache.size() - 1; i >= 0; --i)
            {
                bitset<26> bitcache_till_now = array_char_bitcache[i];
                if ((bitcache_till_now & curr_char_bitcache).any())
                    continue;

                array_char_bitcache.push_back(bitcache_till_now | curr_char_bitcache);

                result = max(result, (int)bitcache_till_now.count() + size);
            }
        }
        return result;
    }
};

int main()
{
    // vector<string> arr = {"cha", "r", "act", "ers"};
    vector<string> arr = {"un", "iq", "ue"};
    Solution obj;

    cout << obj.maxLength(arr);

    return 0;
}