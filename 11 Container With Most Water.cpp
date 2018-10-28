class Solution {
public:
    int maxArea(vector<int>& height) {
        int now = 0;
        int i = 0, j = height.size()-1;
        while(i < j){
            now = max(now, min(height[i], height[j]) * (j - i));
            if(height[i] <= height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return now;
    }
};