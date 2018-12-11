class Solution {
public:
    bool isSubsequence(string s, string t) {
        int read_s = 0, si = s.size();
        for(auto i:t){
            if(s[read_s] == i)
                ++read_s;
            if(read_s == si)
                return true;
        }
        return read_s == si;
    }
};