#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string minWindow(string Str, string pattern)
    {
        vector<int> count(128);
        int required = pattern.size();
        int offset = -1;
        int minLen = Str.size() + 1;

        for (const auto &eachChar : pattern)
            ++count[eachChar];

        for (int left = 0, right = 0; right < Str.size(); ++right)
        {
            if (--count[Str[right]] >= 0)
                --required;
            while (required == 0)
            {
                if (minLen > right - left + 1)
                {
                    minLen = 1 + right - left;
                    offset = left;
                }
                if (++count[Str[left++]] > 0)
                    ++required;
            }
        }

        return offset == -1 ? "" : Str.substr(offset, minLen);
    }
};

int main()
{

    Solution obj;
    cout << obj.minWindow("ADOBECODEBANC", "ABC");

    return 0;
}