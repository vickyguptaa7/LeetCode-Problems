class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int mxSquare=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(matrix[i-1][j-1]=='0')continue;
                dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                mxSquare=max(mxSquare,dp[i][j]*dp[i][j]);
            }
        }        
        return mxSquare;
    }
    // int maximalSquare(vector<vector<char>>& matrix) {
    //     int n=matrix.size(),m=matrix[0].size();
    //     vector<vector<int>>preSum(n+1,vector<int>(m+1,0));
    //     for(int i=1;i<=n;i++)
    //     {
    //         for(int j=1;j<=m;j++)
    //         {
    //             bool isOne=(matrix[i-1][j-1]=='1')?1:0;
    //             preSum[i][j]+=isOne+preSum[i-1][j]+preSum[i][j-1]-preSum[i-1][j-1];
    //         }
    //     }
    //     int mxSide=min(n,m);
    //     int mxSquare=0;
    //     for(int side=1;side<=mxSide;side++)
    //     {
    //         for(int i=side-1;i<n;i++)
    //         {
    //             for(int j=side-1;j<m;j++)
    //             {
    //                 int sum=preSum[i+1][j+1]-
    //                     preSum[i-side+1][j+1]-preSum[i+1][j-side+1]+preSum[i-side+1][j-side+1];
    //                 if(side*side==sum)
    //                     mxSquare=max(mxSquare,sum);
    //             }
    //         }
    //     }
    //     return mxSquare;
    // }
};