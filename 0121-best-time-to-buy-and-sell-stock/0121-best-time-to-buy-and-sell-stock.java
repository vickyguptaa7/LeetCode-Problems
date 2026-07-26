class Solution {
    public int maxProfit(int[] prices) {
        int min_price=prices[0],profit=0;
        for(int i=0;i<prices.length;i++)
        {
            profit=Math.max(profit,prices[i]-min_price);
            min_price=Math.min(min_price,prices[i]);
        }
        return profit;
    }
}