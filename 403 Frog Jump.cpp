class Solution {
public:
    bool canCross(vector<int>& stones) {
        vector<set<int>> data(stones.size(), set<int>());
        //和stones同長度，記錄到每一個點的前次跳躍可能距離有哪些
        map<int, int> index;
        for(int i = 0;i < stones.size();++i)
            index[stones[i]] = i;
        //為方便檢查元素是否存在而建
        if(stones[1] - stones[0] == 1)//第一跳必須是1
            data[1].insert(1);//[1]一定只能從[0]到達，唯一的路徑
        for(int i = 1;i < data.size();++i){
            for(auto& j:data[i]){
                if(index[stones[i] + j] != 0)//如果後面有個石頭是+j跳得到的
                    data[index[stones[i] + j]].insert(j);//在那顆石頭的部分紀錄前次跳躍可能為j
                if(index[stones[i] + j+1] != 0)//如果後面有個石頭是+j+1跳得到的
                    data[index[stones[i] + j+1]].insert(j+1);
                //如果j = 1，j-1就是現在這顆石頭
                if(j != 1 && index[stones[i] + j-1] != 0)//如果後面有個石頭是+j-1跳得到的
                    data[index[stones[i] + j-1]].insert(j-1);
            }
        }
        return !data[data.size()-1].empty();
    }
};