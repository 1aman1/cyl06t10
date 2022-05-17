#include <iostream>
#include <vector>

#define DEBUG false

class Solution
{
public:
    char getMostFreqChar(const std::vector<int> &counter)
    {
        char MostFreqChar;
        int max_freq = -1;

        for (int i = 0; i < 26; i++)
        {
            if (max_freq < counter[i])
            {
                max_freq = counter[i];
                MostFreqChar = 'a' + i;
            }
        }
        return MostFreqChar;
    }

    std::string reorganizeString(std::string s)
    {
        int strLength = s.size();

        if (strLength < 1)
            return "";

        std::vector<int> counter(26, 0);
        // get frequencies loaded
        for (auto currChar : s)
        {
            ++counter[currChar - 'a'];
        }

        // find mostFreqChar & its frequency
        char mostFreqChar = getMostFreqChar(counter);
        int freqOfMostFreqChar = counter[mostFreqChar - 'a'];

        // check if reorganizeString possible by spreading mostfreq char one index apart from each other.
        if (freqOfMostFreqChar > (strLength + 1) / 2)
            return "";

        // else
        int fillerIndex = 0;
        std::string solutionString(strLength, ' ');

        while (freqOfMostFreqChar > 0)
        {
            solutionString[fillerIndex] = mostFreqChar;
            fillerIndex += 2;
            --freqOfMostFreqChar;
        }
        // most freq char would get exhausted now.
        counter[mostFreqChar - 'a'] = 0;

        for (int i = 0; i < counter.size(); ++i)
        {
            while (counter[i] > 0)
            { // while the curr element has appearances
                fillerIndex = (fillerIndex >= strLength) ? 1 : fillerIndex;
                solutionString[fillerIndex] = 'a' + i;
                fillerIndex += 2;
                --counter[i];
            }
        }
        return solutionString;
    }
};

int main()
{
    Solution obj;
    std::string s = "aaab";

    std::string res = obj.reorganizeString(s);
    if (res.empty())
        std::cout << "reorganizeString not possible\n";
    else
        std::cout << "Result :" << res << std::endl;

    return 0;
}