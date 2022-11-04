#include <iostream>
#include <map>

class Solution
{
public:
    int count = 0;

    std::map<std::string, bool> map;

    void permutation(std::string S, int l, int r);
};

void Solution::permutation(std::string S, int l, int r)
{
    if (l != r)
    {
        for (int i = l; i <= r; i++)
        {
            std::swap(S[l], S[i]);
            permutation(S, l + 1, r);
            std::swap(S[l], S[i]);
        }
    }
    else
    {
        if (!map.count(S))
        {
            ++count;
            map.insert({S, true});
        }
    }
}

int main()
{
    Solution obj;

    std::string s = "racecar";

    obj.permutation(s, 0, s.size() - 1);

    std::cout << obj.count << std::endl;

    return 0;
}