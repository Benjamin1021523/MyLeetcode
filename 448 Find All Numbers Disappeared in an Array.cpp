class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> nums) {
        for(int i = 0;i < nums.size();++i){
            while(nums[nums[i]-1] != 0 && nums[i] != 0){
                int tar = nums[i]-1;
                swap(nums[i], nums[nums[i]-1]);
                nums[tar] = 0;
            }
        }
        vector<int> re;
        for(int i = 0;i < nums.size();++i){
            if(nums[i] != 0)
                re.push_back(i+1);
        }
        return re;
    }
};