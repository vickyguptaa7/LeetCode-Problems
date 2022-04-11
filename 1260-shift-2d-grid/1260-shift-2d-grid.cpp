class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int r=grid.size(),c=grid[0].size();
        
        for(int i=0;i<k;i++)
        {
            int prev=grid[r-1][c-1];
            for(int j=0;j<r;j++)
            {
                for(int p=0;p<c;p++)
                {
                    int temp=grid[j][p];
                    grid[j][p]=prev;
                    prev=temp;
                }
                    
            }
        }
        return grid;
    }
};