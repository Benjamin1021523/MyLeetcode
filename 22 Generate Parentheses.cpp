class Solution {
public:
    vector<string> generateParenthesis(int n) {
        M = n;
        f("", 0);
        return re;
    }
private:
    void f(string pre, int l){
        if(l == M){
            re.push_back(pre + string(2 * M - pre.size(), ')'));
            return;
        }
        for(;pre.size() <= 2 * l;pre += ')'){
            f(pre + '(', l + 1);
        }
    }
    int M;
    vector<string> re; 
};