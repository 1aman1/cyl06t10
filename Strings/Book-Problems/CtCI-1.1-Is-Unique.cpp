#include <iostream>
#include <unordered_map>

using namespace std;

// map
bool isUnique(std::string str)
{
    unordered_map<char, int> cache;

    for (int i = 0; i < str.length(); ++i)
    {
        if (cache.count(str[i]))
            return false;
        cache[str[i]] = true;
    }

    return true;
}

int main()
{
    std::string str1 = "aman";
    std::string str2 = "gupta";

    std::cout << std::boolalpha << isUnique(str1) << std::endl;
    std::cout << std::boolalpha << isUnique(str2) << std::endl;

    return 0;
}
