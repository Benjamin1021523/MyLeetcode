//407 Trapping Rain Water II的原型
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3)
            return 0;
        int ceiling = height[0];
        for(auto& i:height)
            ceiling = max(ceiling, i);
        vector<int> water(height.size(), ceiling);
        water[0] = height[0];
        water[water.size()-1] = height[height.size()-1];
        int cnt, temp;
        do{
            cnt = 0;
            for(int i = 1, j = water.size()-2;i <= j;++i,--j){
                if(water[i] != (temp = max(height[i], min(water[i-1], water[i+1])))){
                    water[i] = temp;
                    ++cnt;
                }
                if(water[j] != (temp = max(height[j], min(water[j-1], water[j+1])))){
                    water[j] = temp;
                    ++cnt;
                }
            }
        }while(cnt);
        int re = 0;
        for(int i = 0;i < water.size()-1;++i)
            re += water[i] - height[i];
        return re;
    }
};