class Solution {
public:
    vector<int>moveX={2,2,-2,-2,1,1,-1,-1};
    vector<int>moveY={1,-1,1,-1,2,-2,2,-2};
    double helper(int r,int c,int k,int n,vector<vector<vector<double>>>&dp)
    {
        if(r>=n||c>=n||c<0||r<0)
            return 0;
        if(k==0)
            return 1;
        if(dp[r][c][k]!=-1)
            return dp[r][c][k];
        double prob=0;
        for(int i=0;i<8;i++)
        {
            prob+=helper(r+moveX[i],c+moveY[i],k-1,n,dp);
        }
        prob/=8;
        return dp[r][c][k]=prob;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>>
            dp(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1)));
        return helper(row,column,k,n,dp);
    }
};