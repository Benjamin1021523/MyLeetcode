class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0;i < nums.size();++i){
            if(!nums[i]){
                ++cnt;
                nums.erase(nums.begin()+i);
                --i;
            }
        }
        nums.insert(nums.end(), cnt, 0);
    }
};