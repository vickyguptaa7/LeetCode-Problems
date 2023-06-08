class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int row=0,col=m-1;
        int counter=0;
        while(row<n)
        {
            while(col>=0&&grid[row][col]<0)
                col--;
            counter+=(m-col-1);
            row++;
        }
        return counter;
    }
};