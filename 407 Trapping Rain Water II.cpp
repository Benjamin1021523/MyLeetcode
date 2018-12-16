//改寫自contest week6，16名dehua2的答案
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if((n = heightMap.size()) < 3 || (m = heightMap[0].size()) < 3)
            return 0;

        int ceiling = heightMap[0][0];//記錄最大值
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                ceiling = max(ceiling, heightMap[i][j]);
            }
        }
        for(auto& i:heightMap)
            h_map.push_back(i);
        h_ind.assign(n-2, vector<int>(m, ceiling));

        //把h_ind邊緣的部分寫為實際上的高度，蓄水量 = 0
        //上下兩行使用insert和push_back比逐項寫入略快，又比assign快些
        h_ind.insert(h_ind.begin(), h_map[0]);
        h_ind.push_back(h_map[n-1]);
        for(int i = 1;i < n-1;++i){
            h_ind[i][0] = h_map[i][0];
            h_ind[i][m-1] = h_map[i][m-1];
        }
        int count;//用來記錄每圈更新了幾個值
        do{//使用do while純粹為了偷一次count宣告不初始化
            count = 0;
            for(int i = 1, j = n-2;i <= j;++i, --j){//由四角向中間逼近
                for(int k = 1, l = m-2;k <= l;++k, --l){
                    //h_ind[a][b]如果被降到等於h_map[a][b]，表示沒有蓄水功能，以後也不會有
                    if(h_map[i][k] != h_ind[i][k] && i != j && k != l && update(i, k))
                        ++count;//左上
                    if(h_map[i][l] != h_ind[i][l] && i != j && update(i, l))
                        ++count;//右上
                    if(h_map[j][k] != h_ind[j][k] && k != l && update(j, k))
                        ++count;//左下
                    if(h_map[j][l] != h_ind[j][l] && update(j, l))
                        ++count;//右下
                }
            }
        }while(count);

        int re = 0;
        for (int i = 1; i < n-1; i++){
            for (int j = 1; j < m-1; j++){
                re += h_ind[i][j] - h_map[i][j];
            }
        }
        return re;
    }
    vector<vector<int>> h_map;
    vector<vector<int>> h_ind;//記錄每格的水能裝到多高的位子
    int n, m;
    bool update(int i, int j){
        int origin = h_ind[i][j];
        h_ind[i][j] = min(min(h_ind[i-1][j], h_ind[i+1][j]), 
                          min(h_ind[i][j-1], h_ind[i][j+1]));
        h_ind[i][j] = max(h_map[i][j], h_ind[i][j]);
        return origin != h_ind[i][j];//h_ind[i][j] >= h_map[i][j]
    }
};
/**
想像成建立把整個結構包住的長方體，然後把外框減到原本的高度
然後逐步確認水會不會從旁邊漏掉，如果會就往下修正，直到原本結構的高度
最後減掉原本結構的體積，就是蓄水量了
*/