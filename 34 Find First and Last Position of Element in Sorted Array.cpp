class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return {-1, -1};
        int l = 0, r = nums.size(), m;
        vector<int> re(2, -1);
        while(l != r){
            m = (l + r) / 2;
            if(nums[m] > target){
                //if(r == m)  break;
                r = m;
            }
            else if(nums[m] < target){
                if(l == m)  break;
                l = m;
            }
            else{
                re[0] = re[1] = m;
                while(re[0] >= 0 && nums[re[0]] == target)
                    --re[0];
                while(re[1] < nums.size() && nums[re[1]] == target)
                    ++re[1];
                ++re[0], --re[1];
                return re;
            }
        }
        return re;
    }
};