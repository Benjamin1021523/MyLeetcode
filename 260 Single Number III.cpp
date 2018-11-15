class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int, bool> m;
        for(auto& i:nums){
            m[i] ^= 1;
        }
        vector<int> re;
        for(auto& i:m){
            if(i.second){
                re.push_back(i.first);
                if(re.size() == 2)
                     break;
            }
        }
        return re;
    }
};