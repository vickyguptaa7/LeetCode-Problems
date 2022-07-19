class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>dp;
        dp.push_back({1});
        for(int i=1;i<numRows;i++)
        {
            vector<int>row={1};
            int rsize=dp.size();
            for(int j=1;j<dp[rsize-1].size();j++)
            {
                row.push_back(dp[rsize-1][j]+dp[rsize-1][j-1]);
            }
            row.push_back(1);
            dp.push_back(row);
        }
        return dp;
    }
};