class Solution {
    int dp[71][71][71];
    vector<int>moveY={-1,0,1};
public:
    
    int helper(int x,int y1,int y2,vector<vector<int>>&grid)
    {
        int n=grid.size(),m=grid[0].size();
        if(x+1==n)
            return 0;
        
        if(dp[x][y1][y2]!=-1)
            return dp[x][y1][y2];
        
        int cost=0;
        for(int i=0;i<3;i++)
        {
            int _y1=moveY[i]+y1;
            if(_y1>=m||_y1<0)continue;
            
            for(int j=0;j<3;j++)
            {
                int _y2=moveY[j]+y2;
                if(_y2>=m||_y2<0)continue;                
                
                int curr_cost=_y1==_y2?grid[x+1][_y1]:grid[x+1][_y1]+grid[x+1][_y2];
                cost=max(cost,helper(x+1,_y1,_y2,grid)+curr_cost);
            }
        }
        return dp[x][y1][y2]=cost;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n=grid.size(),m=grid[0].size();
        return helper(0,0,m-1,grid)+grid[0][0]+grid[0][m-1];
    }
};