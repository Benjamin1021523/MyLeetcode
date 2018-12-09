class Solution {
public:
    int firstUniqChar(string s) {
        int i = 0;
        for(;i < s.size();++i){
            if(s.find_first_of(s[i]) == s.find_last_of(s[i]))
                return i;
        }
        return -1;
    }
};