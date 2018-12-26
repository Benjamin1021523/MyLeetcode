//驚了，單純的set比radix sort還快
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        set<int> s;
        for(auto& i:nums){
            s.insert(i);
        }
        int re = 0;
        int t = 1;
        int pre = *(s.begin());
        for(auto i = ++s.begin();i != s.end();++i){
            if(*i == pre + 1){
                ++t;
            }
            else{
                re = max(re, t);
                t = 1;
            }
            pre = *i;
        }
        re = max(re, t);
        return re;
    }
};