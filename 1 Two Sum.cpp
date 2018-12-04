class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for(int i = 0;i < nums.size();++i){
            if(m[nums[i]] && nums[i] * 2 == target){
                //由同個數字組成的情況
                return {m[nums[i]] - 1, i};
            }
            m[nums[i]] = i+1;
        }
        for(auto& i:m){
            if(i.second && m[target - i.first])//有n就找找target-n
                return {i.second - 1, m[target - i.first] - 1};
        }
        return {};//並不會用到
    }
};