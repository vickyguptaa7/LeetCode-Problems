class Solution {
public:
    
    int helper(int strt,bool isAlice,vector<int>&stoneValue,vector<vector<int>>&dp)
    {
        if(strt==stoneValue.size())
        {
            return 0;
        }
        
        if(dp[strt][isAlice]!=-1)
            return dp[strt][isAlice];
        
        int val=isAlice?-1e9:1e9,sum=0;
        for(int i=strt;i<min(strt+3,(int)stoneValue.size());i++)
        {
            sum+=stoneValue[i];
            if(isAlice)
                val=max(val,sum+helper(i+1,!isAlice,stoneValue,dp));
            else 
                val=min(val,helper(i+1,!isAlice,stoneValue,dp));
        }
        return dp[strt][isAlice]=val;
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        vector<vector<int>>dp(stoneValue.size(),vector<int>(2,-1));
        int amount=helper(0,1,stoneValue,dp);
        int sum=accumulate(stoneValue.begin(),stoneValue.end(),0);
        if(2*amount==sum)
            return "Tie";
        else if(2*amount>sum)
            return "Alice";
        else 
            return "Bob";
    }
};