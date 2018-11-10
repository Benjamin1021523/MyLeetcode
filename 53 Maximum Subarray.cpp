class Solution {
public:
    int maxSubArray(vector<int> nums) {
        nums.insert(nums.begin(), 0);
        for(int i = 1;i < nums.size();++i){
            nums[i] += nums[i-1];
        }
        int max = nums[nums.size()-1];
        int bottom = nums[0];
        for(int i = 0;i < nums.size()-1;++i){
            if(nums[i] > bottom)
                continue;
            bottom = nums[i];
            for(int j = i+1;j < nums.size();++j){
                if(max < nums[j] - bottom)
                    max = nums[j] - bottom;
            }
        }
        return max;
    }
};