class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int temp;
        int length = matrix.size();
        for(int i = 0;i < length / 2;++i){
            for(int j = i;j < length-i-1;++j){
                temp = matrix[i][j];
                matrix[i][j] = matrix[length-j-1][i];
                matrix[length-j-1][i] = matrix[length-i-1][length-j-1];
                matrix[length-i-1][length-j-1] = matrix[j][length-i-1];
                matrix[j][length-i-1] = temp;
            }
        }
    }
};