#include <iostream>
#include <vector>

int countSubArrays(const std::vector<int> &array, const int &k)
{
    std::vector<int> kMod(k, 0);

    int cumulativeSum = 0;
    for (int i = 0; i < array.size(); ++i)
    {
        cumulativeSum += array[i];
        int tmp;
        tmp = cumulativeSum % k;
        // tmp = ((cumulativeSum % k) + k) % k;

        ++kMod[tmp];
    }

    int count = 0;
    for (int i = 0; i < k; ++i)
    {
        if (kMod[i] > 1)
        {
            count += (kMod[i] * (kMod[i] - 1)) / 2;
        }
    }
    count += kMod[0];

    return count;
}

int main()
{

    std::vector<int> array = {4, 5, 0, -2, -3, 1};
    int k = 5;

    std::cout << countSubArrays(array, k);

    return 0;
}