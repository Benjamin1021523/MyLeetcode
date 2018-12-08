class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int edge = 0;
        for(auto i:grid){
            for(auto j:i)
                edge = max(edge, j);
        }

        for(int i = m-2;i >= 0;--i)
            grid[i].push_back(n*m*edge);
        grid[m-1].push_back(0);
        grid.push_back(vector<int>(n-1, n*m*edge));
        grid[m].push_back(0);

        for(int i = n-1;i > 0;--i)
            grid[m-1][i-1] += grid[m-1][i];
        for(int i = m-2;i >= 0;--i){
            for(int j = n-1;j >= 0;--j){
                grid[i][j] += min(grid[i+1][j], grid[i][j+1]);
            }
        }

        return grid[0][0];
    }
};