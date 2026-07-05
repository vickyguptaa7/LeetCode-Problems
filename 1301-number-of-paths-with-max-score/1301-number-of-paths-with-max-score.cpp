class Solution {
public:

    int helper(int x,int y,vector<string>&board,vector<vector<int>>&dp)
    {
        int n=board.size();
        if(x<0||y<0||x>=n||y>=n||board[x][y]=='X')
            return -1e9;
        if(x==0&&y==0)
        {
            return 0;
        }
        if(dp[x][y]!=-1)
            return dp[x][y];
        
        int val = board[x][y]=='S'?0:board[x][y]-'0';
        return dp[x][y]=val+max({helper(x-1,y,board,dp),helper(x,y-1,board,dp),helper(x-1,y-1,board,dp)});
    }

    int helper1(int x,int y,int maxSum,vector<string>&board,vector<vector<vector<int>>>&dp)
    {
        int n=board.size();
        if(x<0||y<0||x>=n||y>=n||board[x][y]=='X'||maxSum<0)
            return 0;
        if(x==0&&y==0)
        {
            return maxSum==0;
        }
        if(dp[x][y][maxSum]!=-1)
            return dp[x][y][maxSum];
        
        int mod=1e9+7;
        int val = board[x][y]=='S'?0:board[x][y]-'0';
        long long ans = helper1(x-1,y,maxSum-val,board,dp)+helper1(x,y-1,maxSum-val,board,dp)+helper1(x-1,y-1,maxSum-val,board,dp);
        return dp[x][y][maxSum]=ans%mod;
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int maxSum=helper(n-1,n-1,board,dp);
        if(maxSum<0)
            return {0,0};
        vector<vector<vector<int>>>dp1(n,vector<vector<int>>(n,vector<int>(2000,-1)));
        return {maxSum,helper1(n-1,n-1,maxSum,board,dp1)};
    }
};