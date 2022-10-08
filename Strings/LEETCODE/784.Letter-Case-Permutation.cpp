#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    vector<string> result;

public:
    vector<string> letterCasePermutation(string str)
    {
        util(str, 0);
        return result;
    }

private:
    void util(string &str, int i)
    {
        if (i == str.size())
        {
            result.push_back(str);
            return;
        }

        if (isdigit(str[i]))
        {
            util(str, i + 1);
            return;
        }
        str[i] = toupper(str[i]);
        util(str, i + 1);
        str[i] = tolower(str[i]);
        util(str, i + 1);
    }
};

int main()
{

    Solution obj;

    for (const auto &i : obj.letterCasePermutation("a1b2c3"))
        cout << i << " ";

    return 0;
}