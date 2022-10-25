#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        list<char> word1Buffer;

        for (int i = 0; i < word1.size(); ++i)
        {
            string currWord = word1[i];
            for (int l = 0; l < currWord.size(); ++l)
            {
                word1Buffer.push_back(currWord[l]);
            }
        }

        for (int i = word2.size() - 1; i >= 0; --i)
        {
            string currWord = word2[i];
            for (int l = currWord.size() - 1; l >= 0; --l)
            {
                if (currWord[l] != word1Buffer.back())
                    return false;
                word1Buffer.pop_back();
            }
        }

        return true;
    }
};

int main()
{
    Solution obj;

    // vector<string> word1 = {"ab", "c"};
    // vector<string> word2 = {"a", "bc"};
    vector<string> word1 = {"abc", "d", "defg"};
    vector<string> word2 = {"abcddefg"};

    cout << boolalpha
         << obj.arrayStringsAreEqual(word1, word2)
         << "\n";

    return 0;
}