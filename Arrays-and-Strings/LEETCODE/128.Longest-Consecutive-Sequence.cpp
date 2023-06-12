class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0, right = s.size() - 1;

        while (left < right)
        {
            while (!std::isalnum(s[left]) && left < right)
                ++left;

            while (!std::isalnum(s[right]) && left < right)
                --right;

            if (isupper(s[left]))
                s[left] = tolower(s[left]);

            if (isupper(s[right]))
                s[right] = tolower(s[right]);

            if (s[left] != s[right])
                return false;

            ++left;
            --right;
        }

        return true;
    }
};
