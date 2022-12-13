class Solution {
public:
    vector<int>moveY={-1,0,1};
    int helper(int x,int y,int n,vector<vector<int>>&matrix,vector<vector<int>>&dp)
    {
        int minSum=1e9;
        if(dp[x][y]!=-1)return dp[x][y];
        for(int i=0;i<3;i++)
        {
            int _x=x+1,_y=y+moveY[i];
            if(_x==n)
                return 0;
            if(_y==n||_y<0)
                continue;
            minSum=min(minSum,matrix[_x][_y]+helper(_x,_y,n,matrix,dp));
        }
        return dp[x][y]=minSum;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int minSum=1e9;
        for(int i=0;i<n;i++)
        {
            minSum=min(minSum,matrix[0][i]+helper(0,i,n,matrix,dp));
        }
        return minSum;
    }
};