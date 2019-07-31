class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        int len = 0;
        for(auto& i: nums){
            s.insert(i);
            if(len == s.size())
                return true;
            ++len;
        }
        return false;
    }
};
