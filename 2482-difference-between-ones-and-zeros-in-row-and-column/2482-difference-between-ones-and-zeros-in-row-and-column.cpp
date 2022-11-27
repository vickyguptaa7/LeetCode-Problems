class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int>rowsOne(n,0),colsOne(m,0);
        vector<vector<int>>diff(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            int ocnt=0;
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    ocnt++;
            }
            rowsOne[i]=ocnt;
        }
        for(int i=0;i<m;i++)
        {
            int ocnt=0;
            for(int j=0;j<n;j++)
            {
                if(grid[j][i]==1)
                    ocnt++;
            }
            colsOne[i]=ocnt;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                diff[i][j]=2*rowsOne[i]+2*colsOne[j]-(n+m);
            }
        }
        return diff;
    }
};