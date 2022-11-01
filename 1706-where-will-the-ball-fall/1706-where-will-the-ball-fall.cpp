class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int>res(m,-1);
        for(int i=0;i<m;i++)
        {
            int row=0,col=i;
            while(row<n&&col<m)
            {
                if(grid[row][col]==1)
                {
                    if(col==m-1||grid[row][col+1]==-1)
                        break;
                    row++;
                    col++;
                }
                else
                {
                    if(col==0||grid[row][col-1]==1)
                        break;
                    row++;
                    col--;
                }
                
            }
            if(row==n)
            {
                res[i]=col;
            }
        }
        return res;
    }
};