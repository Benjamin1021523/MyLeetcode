//從底下往上累加的方法，反向也可以
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        for(auto& i:A){
            myvec.push_back(i);
        }
        for(int i = myvec.size()-2;i >= 0;--i){
            myvec[i][0] += (myvec[i+1][0] < myvec[i+1][1] ? myvec[i+1][0] : myvec[i+1][1]);
            myvec[i][myvec[i].size()-1] += (myvec[i+1][myvec[i].size()-2] < myvec[i+1][myvec[i].size()-1] ? myvec[i+1][myvec[i].size()-2] : myvec[i+1][myvec[i].size()-1]);
            for(int j = 1;j < myvec[i].size()-1;++j){
                if(myvec[i+1][j-1] <= myvec[i+1][j] && myvec[i+1][j-1] <= myvec[i+1][j+1])
                    myvec[i][j] += myvec[i+1][j-1];
                else if(myvec[i+1][j] <= myvec[i+1][j-1] && myvec[i+1][j] <= myvec[i+1][j+1])
                    myvec[i][j] += myvec[i+1][j];
                else
                    myvec[i][j] += myvec[i+1][j+1];
            }
        }
        int min = myvec[0][0];
        for(int i = 1;i < myvec[0].size();++i){
            if(myvec[0][i] < min)
                min = myvec[0][i];
        }
        return min;
    }
private:
    vector<vector<int>> myvec;
};