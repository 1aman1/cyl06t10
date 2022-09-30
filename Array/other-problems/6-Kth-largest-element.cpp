#include <iostream>
#include <vector>
#include <algorithm>

int Kth_largest_element_2(std::vector<int> array, int K)
{
    int size = array.size();

    if (K > size)
        return -1;

    std::sort(array.begin(), array.end());

    return array[size - K];
}

int Kth_largest_element_1(std::vector<int> array, size_t K)
{
    if (K > array.size())
        return -1;

    auto begin = array.begin();
    auto max = array.begin();
    auto end = array.end();

    while (K > 0)
    {
        max = std::max_element(begin, end);
        end = std::remove(array.begin(), array.end(), *max);
        --K;
    }

    return *(std::max_element(begin, end));
}

int main()
{

    std::vector<int> array = {4, 2, 9, 7, 5, 6, 7, 1, 3};

    std::cout << Kth_largest_element_1(array, 7);
    std::cout << Kth_largest_element_2(array, 7);

    return 0;
}