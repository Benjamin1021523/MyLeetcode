class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int data = 0;
        for(int i = 0;i < 9;++i){
            data = 0;
            for(int j = 0;j < 9;++j){
                if(board[i][j] == '.')
                    continue;
                if(data & (1 << (board[i][j] - '0')))
                    return false;
                data |= (1 << (board[i][j] - '0'));
            }
            data = 0;
            for(int j = 0;j < 9;++j){
                if(board[j][i] == '.')
                    continue;
                if(data & (1 << (board[j][i] - '0')))
                    return false;
                data |= (1 << (board[j][i] - '0'));
            }
        }
        for(int i = 0;i < 7;i += 3){
            for(int j = 0;j < 7;j += 3){
                data = 0;
                for(int k = i;k < i+3;++k){
                    for(int l = j;l < j+3;++l){
                        if(board[k][l] == '.')
                            continue;
                        if(data & (1 << (board[k][l] - '0')))
                            return false;
                        data |= (1 << (board[k][l] - '0'));
                    }
                }
            }
        }
        return true;
    }
};