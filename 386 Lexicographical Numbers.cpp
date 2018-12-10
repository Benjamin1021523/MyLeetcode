class Solution {
public:
    vector<int> lexicalOrder(int n) {
        limit = n;
        re.resize(n);
        for(int i = 1;i <= 9 && i <= n;++i)
            next(i);
        return re;
    }
private:
    void next(int x){
        re[now++] = x;
        for(int i = x*10;i < x*10+10 && i <= limit;++i){
            next(i);
        }
    }
    int now = 0, limit;
    vector<int> re;
};