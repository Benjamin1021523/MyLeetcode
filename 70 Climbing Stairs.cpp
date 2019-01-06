class Solution {
public:
    int climbStairs(int n) {
        if(n < 4)
            return n;
        int pre[2] = {2, 3};
        for(int i = 4;i < n;++i){
            pre[1] += pre[0];
            pre[0] = pre[1] - pre[0];
        }
        return pre[0] + pre[1];
    }
};