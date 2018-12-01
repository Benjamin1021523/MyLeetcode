class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        for(i = nums.size()-2;i >= 0;--i){
            if(nums[i] < nums[i+1]){
                int j;
                for(j = i+1;j < nums.size() && nums[i] < nums[j];++j){}
                swap(nums[i], nums[j-1]);
                j = i+1;
                int k = nums.size()-1;
                while(k-j >= 1){//後段排序
                    swap(nums[j++], nums[k--]);
                }
                break;
            }
        }
        if(i < 0){
            int j = 0, k = nums.size()-1;
            while(k-j >= 1){//全部排序
                swap(nums[j++], nums[k--]);
            }
        }
    }
};