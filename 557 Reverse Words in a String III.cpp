class Solution {
public:
    string reverseWords(string s) {
        stack<char> a;
        int i = 0, j = 0;
        for(;i < s.size();++i){
            if(s[i] != ' '){
                a.push(s[i]);
            }
            else{
                while(!a.empty()){
                    s[j++] = a.top();
                    a.pop();
                }
                ++j;
            }
        }
        while(!a.empty()){
            s[j++] = a.top();
            a.pop();
        }
        return s;
    }
};