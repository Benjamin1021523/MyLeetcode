class Solution {
public:
    int numTrees(int n) {
        for(int i = 4;i <= n;++i){
            for(int j = 0;j < i;++j){
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp[n];
    }
private:
    int dp[20] = {1, 1, 2, 5};
};