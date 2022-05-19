class Solution {
public:
    
    vector<int>moveX={1,0,-1,0};
    vector<int>moveY={0,1,0,-1};
    
    int dfs(int x,int y,vector<vector<int>>&matrix,vector<vector<int>>&dp)
    {
        int rows=matrix.size(),cols=matrix[0].size();
        
        if(dp[x][y]!=-1)return dp[x][y];
        
        int longestPath=1;
        for(int i=0;i<4;i++)
        {
            int _x=x+moveX[i],_y=y+moveY[i];
            if(_x>=rows||_y>=cols||_x<0||_y<0) continue;
            if(matrix[x][y]<matrix[_x][_y])
            {
                longestPath=max(longestPath,1+dfs(_x,_y,matrix,dp));
            }
        }
        return dp[x][y]=longestPath;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows=matrix.size(),cols=matrix[0].size();
        vector<vector<int>>dp(rows,vector<int>(cols,-1));
        int result=1;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                result=max(result,dfs(i,j,matrix,dp));
            }
        }
        return result;
    }
};