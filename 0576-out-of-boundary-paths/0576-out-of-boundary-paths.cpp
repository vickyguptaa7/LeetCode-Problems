class Solution {
    int dp[51][51][51];
    
    vector<int>moveX={0,0,-1,1};
    vector<int>moveY={1,-1,0,0};
    
public:
    
    int helper(int x,int y,int move,int n,int m)
    {
        if(move==0)
            return 0;
        if(dp[x][y][move]!=-1)
            return dp[x][y][move];
        int res=0,mod=1e9+7;
        for(int i=0;i<4;i++)
        {
            int _x=x+moveX[i],_y=moveY[i]+y;
            if(_x>=n||_x<0||_y>=m||_y<0)
            {
                res++;
                continue;
            }
            res+=helper(_x,_y,move-1,n,m);
            res%=mod;
        }
        return dp[x][y][move]=res;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return helper(startRow,startColumn,maxMove,m,n);
    }
};