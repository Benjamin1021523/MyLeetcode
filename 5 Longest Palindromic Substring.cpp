class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "", temp;
        for(int i = 0;i < s.size() - ans.size()/2;++i){
            temp = check(s, i, 1);
            if(temp.size() > ans.size())
                ans = temp;
            if(s[i] == s[i+1])
                temp = check(s, i, 0);
            if(temp.size() > ans.size())
                ans = temp;
        }
        return ans;
    }
    string check(string& s, int cen, bool odd){
        int l, r;
        if(odd)
            l = cen, r = cen;
        else
            l = cen, r = cen+1;
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            --l,++r;
        }
        return s.substr(l+1, r-l-1);
    }
};