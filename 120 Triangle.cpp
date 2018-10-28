class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = 0;i < triangle.size();++i){
            mytr.push_back(triangle[i]);
        }
        for(int i = mytr.size()-2;i >= 0;--i){
            for(int j = 0;j < i + 1;++j){
                mytr[i][j] += (mytr[i+1][j] < mytr[i+1][j+1]?mytr[i+1][j] : mytr[i+1][j+1]);
            }
        }
        return mytr[0][0];
    }
private:
    vector<vector<int>> mytr;
};