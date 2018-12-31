class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        vector<vector<bool>> data(4*grid.size()+1, vector<bool>(4*grid[0].size()+1, 0));
        m = data.size();
        n = data[0].size();
        for(int i = 0;i < grid.size();++i){
            for(int j = 0;j < grid[0].size();++j){
                if(grid[i][j] == '/'){
                    data[i*4+4][j*4] = 1;
                    data[i*4+3][j*4+1] = 1;
                    data[i*4+2][j*4+2] = 1;
                    data[i*4+1][j*4+3] = 1;
                    data[i*4][j*4+4] = 1;
                }
                if(grid[i][j] == '\\'){
                    data[i*4][j*4] = 1;
                    data[i*4+1][j*4+1] = 1;
                    data[i*4+2][j*4+2] = 1;
                    data[i*4+3][j*4+3] = 1;
                    data[i*4+4][j*4+4] = 1;
                }
            }
        }
        int cnt = 0;
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                if(!data[i][j]){
                    ++cnt;
                    draw(data, i, j);
                }
            }
        }
        return cnt;
    }
private:
    void draw(vector<vector<bool>>& data, int i, int j){
        if(data[i][j])
            return;
        data[i][j] = 1;
        if(j != 0)
            draw(data, i, j-1);
        if(i != 0)
            draw(data, i-1, j);
        if(j != n-1)
            draw(data, i, j+1);
        if(i != m-1)
            draw(data, i+1, j);
    }
    int m, n;
};