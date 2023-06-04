#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int K)
    {
        int result = 0;
        int runningPrefix = 0;

        vector<int> count(K);
        count[0] = 1;

        for (const int &eachNum : nums)
        {
            runningPrefix = (runningPrefix + eachNum % K + K) % K;
            result += count[runningPrefix];
            ++count[runningPrefix];
        }

        return result;
    }
};

int main()
{
    Solution obj;

    std::vector<int> array = {4, 5, 0, -2, -3, 1};
    int k = 5;

    std::cout << obj.subarraysDivByK(array, k);

    return 0;
}