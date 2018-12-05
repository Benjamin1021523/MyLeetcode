class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0)
            return {{}};
        if(nums.size() == 1)
            return {{nums[0]}};
        if(nums.size() == 2)
            return {{nums[0], nums[1]}, {nums[1], nums[0]}};

        for(int i = 0;i < nums.size();++i){
            compose({}, nums, i);
        }
        return re;
    }
private:
    void compose(vector<int> now, vector<int> remain, int n){
        now.push_back(remain[n]);
        remain.erase(remain.begin()+n);
        if(remain.size() == 2){
            now.insert(now.end(), remain.begin(), remain.end());
            re.push_back(now);
            swap(now[now.size()-1], now[now.size()-2]);
            re.push_back(now);
        }
        else{
            for(int i = 0;i < remain.size();++i)
                compose(now, remain, i);
        }
    }
    vector<vector<int>> re;
};