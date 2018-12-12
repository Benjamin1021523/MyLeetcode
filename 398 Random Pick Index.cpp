class Solution {
public:
    Solution(vector<int> nums) {
        for(int i = 0;i < nums.size();++i){
            record[nums[i]].push_back(i);
        }
    }
    int pick(int target) {
        return record[target][rand() % record[target].size()];
        /**
        //假隨機也是可以的，真是奇怪的題目
        record[target].push_back(record[target][0]);
        record[target].erase(record[target].begin());
        return record[target][0];
        */
    }
    map<int, vector<int>> record;
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */