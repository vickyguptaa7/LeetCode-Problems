class Solution
{
    int dp[201][201];
    public:
    Solution(){
        memset(dp, -1, sizeof dp); 
    }
    int minimumTotal(vector<vector < int>> &triangle, int c = 0, int r = 0)
    {
        int n = triangle.size();
        if (r == n) return 0;
        if (dp[r][c] != -1) return dp[r][c];

        return dp[r][c] = triangle[r][c] + min(minimumTotal(triangle, c, r + 1), minimumTotal(triangle, c + 1, r + 1));
    }
};