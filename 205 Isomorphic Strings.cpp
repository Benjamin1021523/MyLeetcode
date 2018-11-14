class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false;
        char a[128] = {0};
        char b[128] = {0};
        for(int i = 0;i < s.size();++i){
            if(!a[s[i]])
                a[s[i]] = t[i];
            if(!b[t[i]])
                b[t[i]] = s[i];
            if(a[s[i]] != t[i] || b[t[i]] != s[i])
                return false;
        }
        return true;
    }
};