class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = int(s.size())-1;
        while(i <= j){
            s[i] = alphanumeric(s[i]);
            s[j] = alphanumeric(s[j]);
            if(s[i] == s[j]){
                ++i, --j;
                continue;
            }
            if(!s[i]){
                ++i;
                continue;
            }
            if(!s[j]){
                --j;
                continue;
            }
            if(s[i] != s[j])
                return false;
            ++i, --j;
        }
        return true;
    }
    char alphanumeric(char c){
        if(c <= 'Z' && c >= 'A')
            return c | 32;
        if((c <= 'z' && c >= 'a') || (c <= '9' && c >= '0'))
            return c;
        return 0;
    }
};