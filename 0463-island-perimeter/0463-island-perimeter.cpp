class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        int ans=0;
        vector<int>dx={0,0,1,-1};
        vector<int>dy={1,-1,0,0};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!grid[i][j])continue;
                for(int k=0;k<4;k++)
                {
                    int x=i+dx[k],y=j+dy[k];
                    if(x>=n||y>=m||x<0||y<0||!grid[x][y])
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};