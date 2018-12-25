class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i = 0;i < grid.size();++i){
            for(int j = 0;j < grid[0].size();++j){
                if(grid[i][j] == '1'){
                    ++cnt;
                    write(grid, i, j);
                }
            }
        }
        return cnt;
    }
    void write(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size())
            return;
        if(grid[i][j] == '1'){
            grid[i][j] = '0';
            write(grid, i-1, j);
            write(grid, i, j-1);
            write(grid, i+1, j);
            write(grid, i, j+1);
        }
    }
};