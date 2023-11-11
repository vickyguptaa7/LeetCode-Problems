class Solution {
    int dp[100001][2][3][2];
public:
    
    int helper(int indx,int lc,int ec,int tc,int n)
    {
        if(indx==n)
        {
            return (lc==1&&ec==2&&tc==1);
        }
        if(dp[indx][lc][ec][tc]!=-1)
            return dp[indx][lc][ec][tc];
        
        long long ways=0,mod=1e9+7;
        for(int i=0;i<26;i++)
        {
            if(i+'a'=='l')
            {
                ways+=helper(indx+1,min(lc+1,1),ec,tc,n);
            }
            else if(i+'a'=='e')
            {
                ways+=helper(indx+1,lc,min(ec+1,2),tc,n);
            }
            else if(i+'a'=='t')
            {
                ways+=helper(indx+1,lc,ec,min(tc+1,1),n);
            }
            else{
                ways+=helper(indx+1,lc,ec,tc,n);
            }
            ways%=mod;
        }
        return dp[indx][lc][ec][tc]=ways;
    }
    
    int stringCount(int n) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,0,0,n);
    }
};