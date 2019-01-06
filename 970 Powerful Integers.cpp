class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> xv({1});
        vector<int> yv({1});
        int i = 0;
        if(x > 1){
            while(xv[i] < bound){
                xv.push_back(xv[i] * x);
                ++i;
            }
        }
        else if(x == 0)
            xv.push_back(0);
        if(y > 1){
            i = 0;
            while(yv[i] < bound && y != 1){
                yv.push_back(yv[i] * y);
                ++i;
            }
        }
        else if(y == 0)
            xv.push_back(0);
        set<int> re;
        for(i = 0;i < xv.size();++i){
            for(int j = 0;j < yv.size();++j){
                if(xv[i] + yv[j] <= bound){
                    re.insert(xv[i] + yv[j]);
                }
                else
                    break;
            }
        }
        vector<int> ret(re.begin(), re.end());
		//重複項的一種處理法，寫起來很方便但是效率估計不怎麼樣
        return ret;
    }
};