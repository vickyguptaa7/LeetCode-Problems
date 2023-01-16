class Solution {
public:
    
    int helper(int x,int y,vector<vector<int>>&dungeon,vector<vector<int>>&dp)
    {
        int n=dungeon.size(),m=dungeon[0].size();
        if(x>=n||y>=m)
            return 1e9;
        if(x==n-1&&y==m-1)
        {
            return (dungeon[x][y]<=0)?-dungeon[x][y]+1:1;
        }
        if(dp[x][y]!=-1)
            return dp[x][y];
        int right=helper(x,y+1,dungeon,dp);
        int down=helper(x+1,y,dungeon,dp);
        int health=-dungeon[x][y]+min(down,right);
        return dp[x][y]=(health<=0)?1:health;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size(),m=dungeon[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,dungeon,dp);
    }
};