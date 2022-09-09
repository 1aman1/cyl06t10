#include <iostream>
#include <algorithm>

class Solution
{
public:
    int count_with_stl = 0;

    void permute_using_stl(std::string s);
};

void Solution::permute_using_stl(std::string s)
{
    std::sort(s.begin(), s.end());

    do
    {
        ++count_with_stl;
        // std::cout << s << "\n";

    } while (std::next_permutation(s.begin(), s.end()));
}

int main()
{
    Solution obj;

    std::string s = "racecar";
    obj.permute_using_stl(s);

    std::cout << obj.count_with_stl << std::endl;

    return 0;
}