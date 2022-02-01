class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price=prices[0],n=prices.size(),max_profit=0;
        for(int i=1;i<n;i++)
        {
            min_price=min(min_price,prices[i]);
            max_profit=max(max_profit,prices[i]-min_price);
        }
        return max_profit;
    }
};