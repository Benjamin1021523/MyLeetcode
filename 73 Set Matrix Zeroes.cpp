class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> r(matrix.size(), false), c(matrix[0].size(), false);
        for(int i = 0;i < matrix.size();++i){
            for(int j = 0;j < matrix[0].size();++j){
                if(!matrix[i][j]){
                    r[i] = c[j] = true;
                }
            }
        }
        for(int i = 0;i < matrix.size();++i){
            if(r[i]){
                matrix[i].assign(matrix[0].size(), 0);
            }
        }
        for(int i = 0;i < matrix[0].size();++i){
            if(c[i]){
                for(int j = 0;j < matrix.size();++j){
                    matrix[j][i] = 0;
                }
            }
        }
    }
};