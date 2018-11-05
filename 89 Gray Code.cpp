class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> re(1 << n, 0);
        int add = 1;
        for(int i = 1;i <= n;++i){
            for(int j = add - 1, k = add;j >= 0;--j,++k){
                re[k] = add + re[j];
            }
            add <<= 1;
        }
        return re;
    }
};