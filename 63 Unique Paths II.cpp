class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& table) {
        if(table.empty() || table[table.size()-1][table[0].size()-1])
            return 0;
        for(int i = 0;i < table.size();++i){
            nums.push_back({});
            nums[nums.size()-1].insert(nums[nums.size()-1].end(), table[i].size(), 0);
        }
        for(int i = 0;i < table[0].size();++i){
            if(table[0][i])
                break;
            nums[0][i] = 1;
        }
        for(int i = 0;i < table.size();++i){
            if(table[i][0])
                break;
            nums[i][0] = 1;
        }

        for(int i = 1;i < table.size();++i){
            for(int j = 1;j < table[0].size();++j){
                if(table[i][j])
                    continue;
                nums[i][j] = nums[i-1][j] + nums[i][j-1];
            }
        }
        return nums[nums.size()-1][nums[0].size()-1];
    }
private:
    vector<vector<int>> nums;
};