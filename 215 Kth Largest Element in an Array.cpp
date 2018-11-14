class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k + 1;
        map<int, int> m;
        for(int i = 0;i < nums.size();++i){
            ++m[nums[i]];
        }
        for(auto i:m){
            k -= i.second;
            if(k <= 0)
                return i.first;
        }
        return 1;
    }
};