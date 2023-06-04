#include <iostream>
#include <vector>
#include <algorithm>

int smallest_difference(std::vector<int> &arr1, std::vector<int> &arr2)
{
    std::sort(arr1.begin(), arr1.end());
    std::sort(arr2.begin(), arr2.end());

    int i = 0;
    int j = 0;
    int diff = 9999999;

    while (i < arr1.size() && j < arr2.size())
    {
        diff = std::min(diff, std::abs(arr1[i] - arr2[j]));

        if (arr1[i] < arr2[j])
            ++i;
        else
            ++j;
    }

    return diff;
}

int main()
{

    std::vector<int> arr1 = {1, 3, 15, 11, 2};
    std::vector<int> arr2 = {23, 127, 235, 19, 8};

    // std::vector<int> arr1 = {1, 2, 11, 15};
    // std::vector<int> arr2 = {4, 12, 19, 23, 127, 235};

    std::cout << smallest_difference(arr1, arr2) << "\n";

    return 0;
}