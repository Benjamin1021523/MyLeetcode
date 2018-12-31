class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int m = A[0], M = A[0];
        for(int i = 1;i < A.size();++i){
            if(A[i] < m)
                m = A[i];
            else if(A[i] > M)
                M = A[i];
        }
        return max(0, M - m - 2 * K);
    }
};