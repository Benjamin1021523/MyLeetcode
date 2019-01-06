class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int re = 0, n = A.size(), m = A[0].size();
        for(int i = 0;i < m;++i){//檢查字串的每個字元
            int j = 0;
            for(;j < n-1 && A[j][i] <= A[j+1][i];++j){}
            if(j != n-1)
                ++re;
        }
        return re;
    }
};