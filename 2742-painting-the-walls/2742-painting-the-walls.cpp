class Solution {
public:
    
    int helper(int indx,int left,vector<int>&cost,vector<int>&time,vector<vector<int>>&dp)
    {
        if(left<=0)
            return 0;
        if(indx==cost.size())
            return 1e9;
        if(dp[indx][left]!=-1)
            return dp[indx][left];
        
        bool isNotOne=time[indx]!=1;
        return dp[indx][left]=min(helper(indx+1,left,cost,time,dp),
                                 helper(indx+1,left-(time[indx])-1,cost,time,dp)+cost[indx]);
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int size=cost.size();
        vector<vector<int>>dp(size,vector<int>(size+1,-1));
        return helper(0,size,cost,time,dp);
    }
};