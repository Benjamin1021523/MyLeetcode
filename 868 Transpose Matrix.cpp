class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<int> temp(A.size(), 0);
        vector<vector<int>> B(A[0].size(), temp);
        
        for(int i = 0;i < A[0].size();++i){
            for(int j = 0;j < A.size();++j){
                B[i][j] = A[j][i];
            }
        }
        return B;
    }
};