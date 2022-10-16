class Solution {
public:
    
    int helper(int strt,int d,int n,vector<int>&jD,vector<vector<int>>&dp)
    {
        if(strt>=n)
        {
            if(d==0)return 0;
            else return 1e9;
        }
        if(d<0)
            return 1e9;
        
        if(dp[strt][d]!=-1)
            return dp[strt][d];
        
        int Max=0,res=1e9;
        for(int i=strt;i<n;i++)
        {
            Max=max(Max,jD[i]);
            res=min(res,Max+helper(i+1,d-1,n,jD,dp));
        }
        return dp[strt][d]=res;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d)
            return -1;
        vector<vector<int>>dp(n+1,vector<int>(d+1,-1));
        return helper(0,d,n,jobDifficulty,dp);
    }
};