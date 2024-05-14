class Solution {
    
    vector<int>dx={1,-1,0,0},dy={0,0,-1,1};
    
public:
    
    bool check(int x,int y,vector<vector<int>>&grid)
    {
        int n=grid.size(),m=grid[0].size();
        if(x>=n||y>=m||x<0||y<0||!grid[x][y])return true;
        return false;
    }
    
    int helper(int x,int y,vector<vector<int>>&grid)
    {   
        int ans=grid[x][y];
        int curr=grid[x][y];
        grid[x][y]=0;
        for(int i=0;i<4;i++)
        {
            int _x=x+dx[i],_y=y+dy[i];
            if(check(_x,_y,grid))continue;
            ans=max(ans,helper(_x,_y,grid)+curr);
        }
        grid[x][y]=curr;
        return ans;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!grid[i][j])continue;
                ans=max(helper(i,j,grid),ans);
            }
        }
        return ans;
    }
};