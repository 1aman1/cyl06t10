#include <iostream>
#include <vector>

typedef std::vector<int> Arr;

int get_first(const Arr array, int target)
{
    if (target < array.front())
        return -1;

    if (array.front() == target)
        return 0;

    int left = 0, right = array.size() - 1;
    while (left <= right)
    {
        int mid = (right - left) / 2 + left;

        if (target == array[mid] && array[mid - 1] < target)
            return mid;
        else if (target <= array[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}

int get_last(const Arr array, int target)
{
    if (array.back() < target)
        return -1;

    if (array.back() == target)
        return array.size() - 1;

    int left = 0, right = array.size() - 1;
    while (left <= right)
    {
        int mid = (right - left) / 2 + left;

        if (target == array[mid] && array[mid + 1] > target)
            return mid;
        else if (target < array[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}

Arr get_first_last(const Arr array, int target)
{
    Arr result;

    result.push_back(get_first(array, target));
    result.push_back(get_last(array, target));

    return result;
}

int main()
{
    Arr array = {1, 2, 3, 3, 3, 3, 4, 5};
    int target = 3;

    for (auto i : get_first_last(array, target))
        std::cout << i << " ";

    return 0;
}