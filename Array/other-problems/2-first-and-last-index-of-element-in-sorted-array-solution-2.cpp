#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int> Arr;

Arr get_first_last(const Arr array, int target)
{
    Arr result;
    const Arr target_ = {target};

    result.push_back(std::distance(array.begin(),
                                   std::find_first_of(array.begin(), array.end(),
                                                      target_.begin(), target_.end())));
    result.push_back(std::distance(array.begin(),
                                   std::find_end(array.begin(), array.end(),
                                                 target_.begin(), target_.end())));

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