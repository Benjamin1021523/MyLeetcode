class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<int> use;
        for(int i = 0;i < nums.size();++i){
            if(use.find(nums[i]) == use.end()){
                use.insert(nums[i]);
                compose({}, nums, i);
            }
        }
        return re;
    }
private:
    void compose(vector<int> now, vector<int> remain, int n){
        now.push_back(remain[n]);
        remain.erase(remain.begin()+n);
        if(remain.empty())
            re.push_back(now);
        set<int> use;
        for(int i = 0;i < remain.size();++i){
            if(use.find(remain[i]) == use.end()){
                use.insert(remain[i]);
                compose(now, remain, i);
            }
        }
    }
    vector<vector<int>> re;
};