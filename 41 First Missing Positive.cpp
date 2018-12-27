class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> after(nums.size()+1, 0);
        for(int i = 0;i < nums.size();++i){
            if(nums[i] <= 0 || nums[i] > nums.size()){
                nums.erase(nums.begin()+i);
                --i;
                continue;
            }
            after[nums[i]] = 1;
        }
        int re = 1;
        for(;re <= nums.size() && after[re];++re){}
        return re;
    }
};