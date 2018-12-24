//第一次從左到右，在不會從左漏掉的前提下盡量填滿
//第二次從右到左，直到最高的之前，把右邊漏掉的扣掉
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3)
            return 0;
        int lM = height[0], re = 0;
        for(int i = 1;i < height.size();++i){
            lM = max(lM, height[i]);
            re += lM - height[i];
        }
        int rM = height[height.size()-1];
        for(int i = height.size()-1;height[i] != lM;--i){
            rM = max(rM, height[i]);
            re -= lM - rM;
        }
        return re;
    }
};