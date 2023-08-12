class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ogrid) {
        int n=ogrid.size(),m=ogrid[0].size();
        vector<vector<long long>>dp(n,vector<long long>(m,0));
        
        for(int i=n-1;i>=0;i--)
            if(!ogrid[i][m-1])
                dp[i][m-1]=1;
            else 
                break;
        
        for(int i=m-1;i>=0;i--)
            if(!ogrid[n-1][i])
                dp[n-1][i]=1;
            else
                break;
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {
                if(ogrid[i][j])continue;
                dp[i][j]=dp[i][j+1]+dp[i+1][j];
            }
        }
        return dp[0][0];
    }
};