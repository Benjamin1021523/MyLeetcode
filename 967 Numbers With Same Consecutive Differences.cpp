class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N == 1)
            re.push_back(0);
        for(int i = 1;i < 10;++i){
            f(N-1, K, i);
        }
        return re;
    }
    void f(int N, int& K, int pre){
        if(N == 0){
            re.push_back(pre);
            return;
        }
        int small = pre % 10;
        pre *= 10;
        if(small + K < 10)
            f(N-1, K, pre + small + K);
        if(small - K >= 0 && K != 0)
            f(N-1, K, pre + small - K);
    }
    vector<int> re;
};