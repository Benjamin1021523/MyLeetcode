class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int re = 0;
        int b = 0, s = 0;
        for(int i = 1;i < prices.size();++i){
            if(prices[s] > prices[i]){
                re += prices[s] - prices[b];
                s = b = i;
            }
            else
                ++s;
        }
        if(s != b)
            re += prices[s] - prices[b];
        return re;
    }
};