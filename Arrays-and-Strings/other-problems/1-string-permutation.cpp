#include <iostream>
#include <algorithm>

class Solution
{
public:
    int count = 0;

    void permutation(std::string S);
};

void Solution::permutation(std::string S)
{
    std::sort(S.begin(), S.end());

    do
    {
        ++count;
    } while (std::next_permutation(S.begin(), S.end()));
}

int main()
{
    Solution obj;

    std::string S = "racecar";
    obj.permutation(S);

    std::cout << obj.count << std::endl;

    return 0;
}