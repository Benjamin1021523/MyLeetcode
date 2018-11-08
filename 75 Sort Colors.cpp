class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3] = {0};
        for(auto& i : nums)
            ++cnt[i];
        nums.assign(cnt[0], 0);
        nums.insert(nums.end(), cnt[1], 1);
        nums.insert(nums.end(), cnt[2], 2);
    }
};