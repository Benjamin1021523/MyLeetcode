class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.find("()") == string::npos)
            return 0;
        int stack = 0, re = 0;
        vector<int> v(1, 0);
        for(auto& i:s){
            if(i == '('){
                ++stack;
                if(stack == v.size())
                    v.push_back(0);
            }
            else{
                --stack;
                if(stack < 0){
                    re = max(re, v[0]);
                    stack = 0;
                    for(int j = stack;j < v.size();++j)
                        v[j] = 0;
                }
                else{
                    v[stack] += 2 + v[stack+1];
                    v[stack+1] = 0;
                    for(int j = stack+1;j < v.size();++j)
                        v[j] = 0;
                }
            }
        }
        for(int i = 0;i <= stack;++i)
            re = max(re, v[i]);
        return re;
    }
};
/**
大致的想法是「在還有stack個'('沒兌現的情況，目前累積了多少長度」
出現')'時兌現一個'('，把之前累積的長度+2疊到stack-1的位子
stack < 0表示前後串不起來，用max(re, v[0]+2)更新re
也有可能出現最後都沒兌現的情況，所以需要最後再檢查一次
*/