class Solution {
public:
    
    int helper(int indx,vector<vector<int>>&pairs,vector<int>&dp)
    {
        if(indx==pairs.size())
        {
            return 0;
        }
        
        if(dp[indx]!=-1)
            return dp[indx];
        
        vector<int>temp={pairs[indx][1],INT_MAX};
        int nindx=upper_bound(pairs.begin(),pairs.end(),temp)-pairs.begin();
        
        return dp[indx]=max(1+helper(nindx,pairs,dp),helper(indx+1,pairs,dp));
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        vector<int>dp(pairs.size(),-1);
        return helper(0,pairs,dp);
    }
};