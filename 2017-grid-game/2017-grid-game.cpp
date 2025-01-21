class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<long long>>prefix(n,vector<long long>(m+1,0));
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                prefix[i][j]=prefix[i][j-1]+grid[i][j-1];
            }
        }
        long long res=1e18;
        for(int i=0;i<m;i++)
        {
            res=min(res,max(prefix[1][i],prefix[0][m]-prefix[0][i+1]));
        }
        return res;
    }
};