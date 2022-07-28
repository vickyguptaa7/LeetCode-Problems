class Solution {
public:
    vector<int>moveX={-2,-1,1,2, 2, 1,-1,-2};
    vector<int>moveY={ 1, 2,2,1,-1,-2,-2,-1};
    int mod=1e9+7;
    bool isValid(int x,int y)
    {
        if(x>=4||x<0||y>=3||y<0)return false;
        
        if((x==3&&y==0)||(x==3&&y==2))return false;
        
        return true;
    }
    int helper(int x,int y,int n,vector<vector<vector<int>>>&dp)
    {
        if(n<=0)return 1;
        if(dp[n][x][y]!=-1)return dp[n][x][y];
        
        long long ways=0;
        for(int i=0;i<8;i++)
        {
            int _x=x+moveX[i],_y=y+moveY[i];
            if(!isValid(_x,_y))continue;
            ways+=helper(_x,_y,n-1,dp);
            ways%=mod;
        }
        return dp[n][x][y]=ways;   
    }
    int knightDialer(int n) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(4,vector<int>(3,-1)));
        long long ans=0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(isValid(i,j))
                {
                    ans+=helper(i,j,n-1,dp);
                    ans%=mod;
                }
            }
        }
        return ans;
    }
};