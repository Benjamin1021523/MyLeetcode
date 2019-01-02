class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int r = nums[0];//最遠能到哪
        for(int i = 1;i < n-1 && r < n-1 && r >= i;++i){
            if(i+nums[i] > r)
                r = i+nums[i];
        }
        return r >= n - 1;
    }
};