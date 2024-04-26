class Solution {
    vector<vector<int>>dp;
public:
    
    int helper(int level,int prev,vector<vector<int>>&grid)
    {
        if(level==grid.size())
        {
            return 0;
        }
        
        if(dp[level][prev+1]!=-1)
            return dp[level][prev+1];
        
        int curr=1e9;
        for(int i=0;i<grid[level].size();i++)
        {
            if(prev==i)continue;
            curr=min(curr,grid[level][i]+helper(level+1,i,grid));
        }
        
        return dp[level][prev+1]=curr;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        dp.resize(grid.size(),vector<int>(grid.size()+1,-1));
        return helper(0,-1,grid);
    }
};