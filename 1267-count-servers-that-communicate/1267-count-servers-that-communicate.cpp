class Solution {
public:

    int countServers(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int>rows(m,0),cols(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!grid[i][j])continue;
                rows[j]++;
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!grid[j][i])continue;
                cols[j]++;
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]&&(rows[j]>1||cols[i]>1))
                    count++;
            }
        }
        return count;
    }
};