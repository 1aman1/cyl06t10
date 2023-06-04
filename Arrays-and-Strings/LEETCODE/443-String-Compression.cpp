#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

class Solution
{
public:
    // int number_of_digits(int num)
    // {
    //     std::string s = std::to_string(num);
    //     return s.size();
    // }

    // int compressed_length(std::vector<char> &chars)
    // {
    //     int count_consecutive = 0;
    //     int compress_len = 0;
    //     for (int i = 0; i < chars.size(); ++i)
    //     {
    //         ++count_consecutive;

    //         if (chars[i] != chars[i + 1])
    //         {
    //             compress_len += 1  + number_of_digits(count_consecutive);
    //             count_consecutive = 0;
    //         }
    //     }
    //     return compress_len;
    // }

    int compress(std::vector<char> &chars)
    {
        // if (chars.size() <= 1 || compressed_length(chars) >= chars.size())
        //     return chars.size();

        int writeHead = 0;
        int size = chars.size();

        for (int i = 0; i < size;)
        {
            int count_same_char = 0;

            const char curr_char = chars[i];

            while (i < size &&
                   chars[i] == curr_char)
            {
                ++i;
                ++count_same_char;
            }

            chars[writeHead++] = curr_char;

            if (count_same_char > 1)
            {
                for (const auto i : std::to_string(count_same_char))
                    chars[writeHead++] = i;
            }
        }
        // chars.resize(writeHead);
        return writeHead;
    }
};

int main()
{

    Solution obj;

    // std::vector<char> chars{'a', 'b', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c'};
    // std::vector<char> chars{'a', 'b', 'c', 'd'};
    // std::vector<char> chars{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    std::vector<char> chars{'a', 'a'};

    std::cout << obj.compress(chars) << std::endl;

    for (auto &i : chars)
        std::cout << i;

    return 0;
}