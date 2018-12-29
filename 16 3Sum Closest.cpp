class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int re = nums[0] + nums[1] + nums[2];
        int l, r;
        for(int i = 0;i < nums.size()-2;++i){
            l = i+1, r = nums.size()-1;
            while(l < r){
                int temp = nums[i] + nums[l] + nums[r];
                if(temp == target)
                    return target;
                else if(temp > target)
                    --r;
                else
                    ++l;
                if(abs(temp - target) < abs(re - target))
                    re = temp;
            }
        }
        return re;
    }
};