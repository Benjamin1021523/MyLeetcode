class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(int& i:nums){
            s.insert(i);
        }
        if(s.size() < 3)
            return *(--s.end());
        else
            return *(------s.end());
    }
};