class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        for(int i = 0;i < A.size() - 1;++i){
            A[i] -= A[i+1];
        }
        A.erase(A.end()-1);
        
        char op = 0;
        int i = 0;
        for(;i < A.size() && !op;++i){
            if(A[i] < 0)
                op = 1;
            else if(A[i] > 0)
                op = 2;
        }
        for(;i < A.size();++i){
            if(op == 1 && A[i] > 0){
                return false;
            }
            if(op == 2 && A[i] < 0){
                return false;
            }
        }
        return true;
    }
};