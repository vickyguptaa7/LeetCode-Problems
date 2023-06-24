class Solution {
public:
    
    int helper(int indx,int sum,vector<int>&rods,vector<vector<int>>&dp)
    {
        if(rods.size()==indx)
        {
            return sum==5000?0:-1e9;
        }
        
        if(dp[indx][sum]!=-1)
            return dp[indx][sum];
        
        int ways=helper(indx+1,sum,rods,dp);
        ways=max(ways,helper(indx+1,sum-rods[indx],rods,dp)+rods[indx]);
        ways=max(ways,helper(indx+1,sum+rods[indx],rods,dp)+rods[indx]);
        
        return dp[indx][sum]=ways;
    }
    
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        vector<vector<int>>dp(n,vector<int>(10002,-1));
        return helper(0,5000,rods,dp)/2;
    }
};