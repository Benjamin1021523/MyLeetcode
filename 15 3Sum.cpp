class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int leng = nums.size();
        vector<vector<int>> re;
        if(leng > 2){
            for(int i = 0;nums[i] <= 0 && i < leng-2;++i){
                if(i != 0 && nums[i] == nums[i-1])
                    continue;
                int l = i+1, r = leng-1;
                while(l < r){
                    if(nums[i] + nums[l] + nums[r] == 0){
                        re.push_back({nums[i], nums[l], nums[r]});
                        while(l < r && nums[l] == nums[l+1])    ++l;
                        while(l < r && nums[r] == nums[l-1])    --r;
                        ++l, --r;
                    }
                    else if(nums[i] + nums[l] + nums[r] > 0){
                        --r;
                    }
                    else{
                        ++l;
                    }
                }
            }
        }
        return re;
    }
};