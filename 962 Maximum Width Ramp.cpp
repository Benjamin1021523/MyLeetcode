//目前使用的方法非常慢
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        if(A.size() < 2)
            return 0;
        int i = 0, j = A.size()-1;
        int re = 0;
        int mi = A[0];
        for(int i = 0;i < A.size()-re;++i){
            if(A[i] > mi)
                continue;
            int j = A.size()-1;
            while(A[i] > A[j])  --j;
            mi = A[i];
            re = max(re, j-i);
        }
        return re;
    }
};