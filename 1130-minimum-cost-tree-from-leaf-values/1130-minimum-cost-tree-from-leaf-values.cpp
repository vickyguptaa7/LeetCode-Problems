class Solution {
public:
    
    int helper(int strt,int end,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(strt==end)
            return 0;
        int cost=1e9;
        if(dp[strt][end]!=-1)
            return dp[strt][end];
        for(int i=strt;i<end;i++)
        {
            cost=min(cost,
                     helper(strt,i,arr,dp)+helper(i+1,end,arr,dp)+
                     *max_element(arr.begin()+strt,arr.begin()+i+1)*
                     *max_element(arr.begin()+i+1,arr.begin()+end+1));
        }
        return dp[strt][end]=cost;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),-1));
        return helper(0,(int)arr.size()-1,arr,dp);
    }
};