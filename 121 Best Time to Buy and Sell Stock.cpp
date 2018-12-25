class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        int re = 0, top = prices[prices.size()-1];
        for(int i = prices.size()-2;i >= 0;--i){
            if(top < prices[i])
                top = prices[i];
            else if(re < top - prices[i])
                re = top - prices[i];
        }
        return re;
    }
};