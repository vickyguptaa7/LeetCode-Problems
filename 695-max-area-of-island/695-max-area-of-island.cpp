class Solution {
public:
    vector<int>moveR={0,0,1,-1};
    vector<int>moveC={1,-1,0,0};

    bool isValid(int r,int c,vector<vector<int>>&grid,
                vector<vector<int>>&visit)
    {
        int row=grid.size(),col=grid[0].size();
        
        // out of bound check 
        if(r>=row||r<0||c>=col||c<0)
            return false;
        
        // water not land
        if(grid[r][c]==0)return false;
        
        // already visited
        if(visit[r][c])return false;
        
        //land
        return true;
    }
    int helper(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&dp,
               vector<vector<int>>&visit)
    {
        visit[r][c]=true;
        if(dp[r][c]!=-1)
            return dp[r][c];
        
        int area=0;
        
        for(int i=0;i<4;i++)
        {
            int _r=r+moveR[i],_c=c+moveC[i];
            if(isValid(_r,_c,grid,visit))
            area+=1+helper(_r,_c,grid,dp,visit);
        }
        return dp[r][c]=area;
    }
        
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        int ans=0;
        vector<vector<int>>visit(row,vector<int>(col,false));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                    ans=max(ans,1+helper(i,j,grid,dp,visit));
            }
        }
        return ans;
    }
};