class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int track = 0;
        for(int i = 0; i < nums.size(); ++i)
            track ^= nums[i];
        return track;
    }
};