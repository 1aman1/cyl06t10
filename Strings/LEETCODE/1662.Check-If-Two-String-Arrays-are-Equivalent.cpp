#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        list<char> W1, W2;

        for (int i = 0; i < word1.size(); ++i)
        {
            string tmp = word1[i];
            for (int l = 0; l < tmp.size(); ++l)
            {
                W1.push_back(tmp[l]);
            }
        }
        for (int i = 0; i < word2.size(); ++i)
        {
            string tmp = word2[i];
            for (int l = 0; l < tmp.size(); ++l)
            {
                W2.push_back(tmp[l]);
            }
        }

        return W1 == W2;
    }
};

int main()
{
    Solution obj;

    vector<string> word1 = {"ab", "c"};
    vector<string> word2 = {"a", "bc"};

    cout << boolalpha
         << obj.arrayStringsAreEqual(word1, word2)
         << "\n";

    return 0;
}