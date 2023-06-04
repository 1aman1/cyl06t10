class Solution
{
public:
    string reverseVowels(string S)
    {
        const unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u',
                                         'A', 'E', 'I', 'O', 'U'};
        int left = 0;
        int right = S.length() - 1;

        while (left < right)
        {
            while (left < right && !vowels.count(S[left]))
                ++left;
            while (left < right && !vowels.count(S[right]))
                --right;
            swap(S[left++], S[right--]);
        }

        return S;
    }
};
