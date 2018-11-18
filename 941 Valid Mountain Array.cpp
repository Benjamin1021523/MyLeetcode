class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size() < 3)
            return false;
        int i = 1;
        while(A[i-1] < A[i] && i < A.size()-1){++i;}
        if(i == 1)
            return false;
        while(A[i-1] > A[i] && i < A.size()){++i;}
        return i == A.size();
    }
};