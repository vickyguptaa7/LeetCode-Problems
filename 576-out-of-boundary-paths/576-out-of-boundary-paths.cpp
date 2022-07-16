class Solution {
public:
    vector<int>moveR={0,0,1,-1};
    vector<int>moveC={1,-1,0,0};
    int mod=1e9+7;
    
    bool isValid(int r,int c,int rows,int cols)
    {
        // checking out of boundary 
        if(r>=rows||r<0||c<0||c>=cols)
            return false;
        
        //safe
        return true;
    }
    
    int helper(int r,int c,int maxMove,int rows,int cols,vector<vector<vector<int>>>&dp)
    {
        if(maxMove==0)
            return 0;
        
        if(dp[r][c][maxMove]!=-1)
            return dp[r][c][maxMove];
        
        long long ans=0,invalid=0;
        for(int i=0;i<4;i++)
        {
            int _r=r+moveR[i],_c=c+moveC[i];
            if(!isValid(_r,_c,rows,cols))
            {
                // count the no of invalid moves
                invalid++;
                continue;
            }
            ans+=helper(_r,_c,maxMove-1,rows,cols,dp);
            ans%=mod;
        }
        // add the invalid moves
        ans+=invalid;
        ans%=mod;
        return dp[r][c][maxMove]=ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return helper(startRow,startColumn,maxMove,m,n,dp);
    }
};