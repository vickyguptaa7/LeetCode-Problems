class Solution {
public:
    
    int helper(int taken,int pos,int n,vector<int>&dp)
    {
        if((1<<n)-1==taken)
            return 1;
        
        if(dp[taken]!=-1)
            return dp[taken];
        
        int ways=0;
        for(int i=0;i<n;i++)
        {
            if(taken&(1<<i))continue;
            if(((i+1)%(pos+1))!=0&&((pos+1)%(i+1))!=0)
                continue;
            ways+=helper(taken|(1<<i),pos+1,n,dp);
        }
        
        return dp[taken]=ways;
    }
    
    int countArrangement(int n) {
        vector<int>dp((1<<n)+1,-1);
        return helper(0,0,n,dp);
    }
};