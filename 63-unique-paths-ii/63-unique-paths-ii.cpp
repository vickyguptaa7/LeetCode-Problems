class Solution {
public:
    
    bool isPathValid(int r,int c,vector<vector<int>>&obstacleGrid)
    {
        int rows=obstacleGrid.size(),cols=obstacleGrid[0].size();
        if(r<0||r>=rows||c<0||c>=cols)
            return 0;
        if(obstacleGrid[r][c]==1)
            return 0;
        
        return 1;
    }
    
    int uniquePathHelper(int r,int c,vector<vector<int>>&obstacleGrid,vector<vector<int>>&dp)
    {
        if(dp[r][c]!=-1)return dp[r][c];
        
        int rows=obstacleGrid.size(),cols=obstacleGrid[0].size();
        
        if(r==rows-1&&c==cols-1)return 1;
        
        int ways=0;
        if(isPathValid(r+1,c,obstacleGrid))
        {
            ways+=uniquePathHelper(r+1,c,obstacleGrid,dp);
        }
        
        if(isPathValid(r,c+1,obstacleGrid))
        {
            ways+=uniquePathHelper(r,c+1,obstacleGrid,dp);
        }
        
        dp[r][c]=ways;
        return ways;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>>dp(100,vector<int>(100,-1));
        if(obstacleGrid[0][0]==1)return 0;
        return uniquePathHelper(0,0,obstacleGrid,dp);
    }
    
};