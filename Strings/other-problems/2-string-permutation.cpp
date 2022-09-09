#include <iostream>
#include <map>

class Solution
{
public:
    int count_without_stl = 0;

    std::map<std::string, bool> map;

    void permute(std::string a, int l, int r);
};

void Solution::permute(std::string a, int l, int r)
{
    if (l != r)
    {
        for (int i = l; i <= r; i++)
        {
            std::swap(a[l], a[i]);
            permute(a, l + 1, r);
            std::swap(a[l], a[i]);
        }
    }
    else
    {
        if (!map.count(a))
        {
            // std::cout << a << std::endl;
            ++count_without_stl;
            map.insert({a, true});
        }
    }
}

int main()
{
    Solution obj;

    std::string s = "racecar";

    obj.permute(s, 0, s.size() - 1);

    std::cout << obj.count_without_stl << std::endl;

    return 0;
}