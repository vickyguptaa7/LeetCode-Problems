class Solution {
public:
    
    vector<int>moveX={0,0,1,-1},moveY={1,-1,0,0};
    
    int helper(int x,int y,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(dp[x][y]!=-1)
            return dp[x][y];
        int lpath=1,n=grid.size(),m=grid[0].size();
        for(int i=0;i<4;i++)
        {
            int _x=moveX[i]+x,_y=y+moveY[i];
            if(_x<0||_y<0||_x>=n||_y>=m||grid[_x][_y]<=grid[x][y])continue;
            lpath=max(lpath,1+helper(_x,_y,grid,dp));
        }
        return dp[x][y]=lpath;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int result=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                result=max(result,helper(i,j,matrix,dp));
            }
        }
        return result;
    }
};