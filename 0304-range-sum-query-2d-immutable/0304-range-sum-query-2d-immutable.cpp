class NumMatrix {
    
    int dp[201][201];
    
    void initializeDp(vector<vector<int>>&matrix)
    {
        int n=matrix.size(),m=matrix[0].size();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j]+=matrix[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
        }
    }
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        memset(dp,0,sizeof(dp));
        initializeDp(matrix);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1]-dp[row1][col2+1]
            -dp[row2+1][col1]+dp[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */