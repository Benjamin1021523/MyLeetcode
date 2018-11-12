class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, bool> m;
        for(auto& i:nums){
            m[i] ^= 1;
        }
        for(auto& i:m){
            if(i.second)
                return i.first;
        }
    }
};