class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int total = nums.size() * nums[0].size();
        if(total % r)
            return nums;
        int one_row = total / r;
        vector<vector<int>> re(r, vector<int>({}));
        int cnt = 0, now = 0;
        for(auto& i:nums){
            for(auto& j:i){
                ++cnt;
                re[now].push_back(j);
                if(cnt == one_row){
                    cnt = 0;
                    ++now;
                }
            }
        }
        return re;
    }
};