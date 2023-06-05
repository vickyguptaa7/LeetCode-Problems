class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mxcost=0,minCost=prices[0];
        for(int i=0;i<prices.size();i++)
        {
            minCost=min(minCost,prices[i]);
            mxcost=max(mxcost,prices[i]-minCost);
        }
        return mxcost;
    }
};