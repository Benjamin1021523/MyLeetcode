class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nums2(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        int h = 0, t = nums.size()-1;
        while(nums2[h] == nums[h]){++h;}
        while(nums2[t] == nums[t]){--t;}
        if(h < t)
            return t-h+1;
        return 0;
    }
};