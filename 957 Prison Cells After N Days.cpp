class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> f1, now(8, 0);
        for(int i = 0;N--;cells = now, ++i){
            for(int j = 1;j < 7;++j){
                now[j] = cells[j-1] == cells[j+1];
            }
            if(i == 0)  f1 = now;
            else if(now == f1){//發現循環
                N %= i;//把後面會循環的部分拿掉
            }
        }
        return cells;
    }
};