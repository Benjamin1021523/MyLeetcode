class Solution {
public:
    int longestPalindrome(string s) {
        map<char, bool> m;
        int re = 0;
        for(auto& i:s){
            m[i] ^= true;
            if(!m[i])
                re += 2;
        }
        return re + (re < s.size());
    }
};