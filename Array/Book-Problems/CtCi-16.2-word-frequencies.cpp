#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

void word_frequency(std::vector<std::string> &dict)
{
    std::unordered_map<std::string, int> cache;

    for (int i = 0; i < dict.size(); ++i)
    {
        if (!cache.count(dict[i]))
            cache[dict[i]] = 1;
        else
            ++cache[dict[i]];
    }

    for (const auto i : cache)
    {
        std::cout << i.first << ":" << i.second << "\n";
    }
}

int main()
{
    std::vector<std::string> dict = {"begin",
                                     "string",
                                     "string", "view", "view", "view", "view", "ltrim", "distance", "distance", "distaNCe", "isspace", "find_if", "find_if", "find_if", "rtrim", "crend"};

    word_frequency(dict);

    return 0;
}
