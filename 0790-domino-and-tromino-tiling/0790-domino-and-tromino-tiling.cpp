class Solution {
    int mod=1e9+7;
public:
    int sum(long long a,long long b)
    {
        return ((a%mod)+(b%mod))%mod;
    }

    int helper(int i,int j,int n,vector<vector<int>>&dp)
    {
        if(i>n||j>n)
        {
            return false;
        }
        if(i==n&&j==n)
        {
            return true;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=0,mod=1e9+7;
        if(i==j)
        {
            // domino
            ans=(sum(ans,sum(helper(i+1,j+1,n,dp),sum(helper(i+2,j,n,dp),helper(i,j+2,n,dp)))));
        }
    }

    int numTilings(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(0,0,n,dp);
    }
};
// possible moves
// domino
// | only when the i==j (+1,+1)
// - any time (+2,0) (0,+2)

// tromino 
// _| only when i == j+1  (+1,+2)
// -| only when i+1 == j. (+2,+1)
// |- or |_ only when i==j both