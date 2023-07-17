class Solution {
public:
    
     
    int helper(int indx,int cntr,int size,vector<int>&slices,vector<vector<int>>&dp)
    {
        if(indx>=size)
            return 0;
        if(dp[indx][cntr]!=-1)
            return dp[indx][cntr];
        int ways=helper(indx+1,cntr,size,slices,dp);
        if(cntr>0)
            ways=max(ways, helper(indx+2,cntr-1,size,slices,dp)+slices[indx]);
        return dp[indx][cntr]=ways;
    }
    
    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
        vector<vector<int>>dp1(n,vector<int>((n/3)+1,-1));
        vector<vector<int>>dp2(n,vector<int>((n/3)+1,-1));
        
        return max(helper(0,n/3,n-1,slices,dp1),helper(1,n/3,n,slices,dp2));
    }
};