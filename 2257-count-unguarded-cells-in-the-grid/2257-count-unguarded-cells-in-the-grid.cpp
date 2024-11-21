class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m,vector<int>(n,0));
        vector<vector<int>>mark(m,vector<int>(n,0));
        for(auto g:guards)
        {
            grid[g[0]][g[1]]=1;
        }
        for(auto w:walls)
        {
            grid[w[0]][w[1]]=2;
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!=1)continue;
                mark[i][j]=1;

                    for(int k=i-1;k>=0;k--) // up
                    {
                        if(grid[k][j]==0)
                            mark[k][j]=1;
                        else 
                            break;
                    }   
                    for(int k=j-1;k>=0;k--) // left
                    {
                        if(grid[i][k]==0)
                            mark[i][k]=1;
                        else 
                            break;
                    }
                for(int k=j+1;k<n;k++) // right
                {
                    if(grid[i][k]!=0)
                        break;
                    mark[i][k]=1;
                }
                for(int k=i+1;k<m;k++) // down
                {
                    if(grid[k][j]!=0)
                        break;
                    mark[k][j]=1;
                }
            }
        }

        for(auto a:mark)
        {
            for(auto b:a)
            {
                ans+=b==1;
            }
        }
        return n*m-ans-(int)walls.size();
    }
};