class Solution
{
    public:

        int mincostTicketsHelper(int start, vector<int> &days, vector<int> &cost,
            vector<int> &dp)
        {
            if (days.size() <= start)
            {
                return 0;
            }
            if (dp[start] != -1)
                return dp[start];

            int min_cost = mincostTicketsHelper(start + 1, days, cost, dp) + cost[0];
            int indx7 = upper_bound(days.begin(), days.end(),
                days[start] + 6) - days.begin();
            min_cost = min(min_cost, mincostTicketsHelper(indx7, days, cost, dp) + cost[1]);
            int indx30 = upper_bound(days.begin(), days.end(),
                days[start] + 29) - days.begin();
            min_cost = min(min_cost, mincostTicketsHelper(indx30, days, cost, dp) + cost[2]);
            return dp[start] = min_cost;
        }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        vector<int> dp(days.size() + 1, -1);
        return mincostTicketsHelper(0, days, costs, dp);
    }
};