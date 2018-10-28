class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> out;
        if(!numRows)
            return out;
        vector<int> a1(1,1);
        out.push_back(a1);
        for(int i = 0;i < numRows-1;++i){
            vector<int> temp(out.size()+1, 0);
            out.push_back(temp);
            for(int j = 0;j < out[i].size();++j){
                out[i+1][j] += out[i][j];
                out[i+1][j+1] += out[i][j];
            }
        }
        return out;
    }
};