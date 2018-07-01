//這方法只能對付two sum，three之後就不適合了
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> out;
        for(int i = 0;i < nums.size() - 1;++i){
            target -= nums[i];
            //我覺得這樣比較快
            for(int j = i + 1;j < nums.size();++j){
                if(nums[j] == target){
                    out.push_back(i);
                    out.push_back(j);
                    return out;
                    break;
                }
            }
            target += nums[i];
        }
    }
};