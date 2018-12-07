class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        int leng = 1 << nums.size();
        for(int i = 0;i < leng;++i){
            vector<int> temp;
            for(int j = 0;j < nums.size();++j){
                if(i & (1 << j))
                    temp.push_back(nums[j]);
            }
            s.insert(temp);
        }
        vector<vector<int>> re;
        for(auto& i:s)
            re.push_back(i);
        return re;
    }
};