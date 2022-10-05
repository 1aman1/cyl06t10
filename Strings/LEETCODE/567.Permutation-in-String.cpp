
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> cache(128);
        int pattern_size = s1.length();
        const int S1_LEN = s1.length();

        for (const auto &each_char : s1)
            ++cache[each_char];

        for (int each_char = 0; each_char < s2.length(); ++each_char)
        {
            if (--cache[s2[each_char]] >= 0)
                --pattern_size;

            if (each_char >= S1_LEN)
            {
                if (++cache[s2[each_char - S1_LEN]] > 0)
                    ++pattern_size;
            }

            if (pattern_size == 0)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution obj;

    string s1 = "ab", s2 = "eidbaooo";

    cout << boolalpha
         << obj.checkInclusion(s1, s2)
         << "\n";

    return 0;
}

// if (++count[s2[r - s1.length()]] > 0)
//     ++required;
