class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        ss = s;
        set<string> se;
        vector<string> re;
        for(int i = 1;i <= 3 && i < ss.size();++i){
            for(int j = i+1;j <= i+3 && j < ss.size();++j){
                for(int k = j+1;k <= j+3 && k < ss.size();++k){
                    if(check(0, i) && check(i, j) && 
                       check(j, k) && check(k, ss.size())){
                        s.insert(k,1,'.');
                        s.insert(j,1,'.');
                        s.insert(i,1,'.');
                        se.insert(s);
                        s = ss;
                    }
                }
            }
        }
        for(auto& i:se)
            re.push_back(i);
        return re;
    }
private:
    bool check(int a, int b){
        if(b-a != 1 && ss[a] == '0' || b-a > 3)
            return false;
        int num = 0;
        for(int i = a;i < b;++i){
            num *= 10;
            num += ss[i] - '0';
        }
        return num < 256;
    }
    string ss;
};