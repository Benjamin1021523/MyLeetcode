class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> re((1 << nums.size()), vector<int>{});
        for(int i = 0;i < re.size();++i){
            for(int j = 0;j < nums.size();++j){
                if(i & (1 << j))
                    re[i].push_back(nums[j]);
            }
        }
        return re;
    }
};
/*
class Solution {
public:
    //gray code的特點是相鄰兩項差一個bit，循環之前不會重覆
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> re((1 << nums.size()), vector<int>{});
        for(int i = 0;i < re.size();++i){
            for(int j = 0;j < nums.size();++j){
                if(i & (1 << j))
                    re[i].push_back(nums[j]);
            }
        }
        return re;
		
		for(int j = 0;j < nums.size();++j){
            for(int i = gray.size()-1;i >= 0;--i){
                gray.push_back((1 << j) + gray[i]);
            }
        }
        vector<vector<int>> re(gray.size(), vector<int>());
        for(int i = 0;i < gray.size();++i){
            for(int j = 0;j < nums.size();++j){
                if(gray[i] & (1 << j))
                    re[i].push_back(nums[j]);
            }
        }
        return re;
    }
private:
    vector<int> gray = {0};
};*/