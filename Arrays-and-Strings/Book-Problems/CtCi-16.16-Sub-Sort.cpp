#include <iostream>
#include <vector>
#include <algorithm>

int get_left_location(const std::vector<int> &arr1, const int &leftEnd, const int &min)
{
    for (int i = leftEnd; i >= 0; --i)
        if (arr1[i] < min)
            return i + 1;
    return 0;
}

int get_right_location(const std::vector<int> &arr1, const int &rightBegin, const int &max)
{
    for (int i = rightBegin; i < arr1.size(); ++i)
        if (arr1[i] > max)
            return i - 1;
    return arr1.size() - 1;
}

int left_end(const std::vector<int> &arr1, const int &arrayLen)
{
    for (int i = 1; i <= arrayLen; ++i)
        if (arr1[i] < arr1[i - 1])
            return i - 1;

    return arrayLen;
}

int right_begin(const std::vector<int> &arr1, const int &arrayLen)
{
    for (int j = arrayLen - 1 - 1; j >= 0; --j)
        if (arr1[j] > arr1[j + 1])
            return j + 1;

    return 0;
}

void sub_sort(const std::vector<int> &arr1)
{
    int arrayLen = arr1.size();

    int leftEnd = left_end(arr1, arrayLen);
    if (leftEnd == arr1.size() - 1) // already sorted
        return;

    int rightBegin = right_begin(arr1, arrayLen);

    int min = 999999;
    int max = -999999;
    for (int i = leftEnd; i <= rightBegin; ++i)
    {
        min = std::min(min, arr1[i]);
        max = std::max(max, arr1[i]);
    }

    std::cout << get_left_location(arr1, leftEnd, min) << "\n";
    std::cout << get_right_location(arr1, rightBegin, max) << "\n";
}

int main()
{

    std::vector<int> arr1 = {1, 2, 4, 7, 10, 11, 8, 12, 5, 6, 16, 18, 19};
    // std::vector<int> arr1 = {1, 2, 3, 4, 5};
    // std::vector<int> arr1 = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};

    sub_sort(arr1);

    return 0;
}