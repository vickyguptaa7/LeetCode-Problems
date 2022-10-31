class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            int row=0,col=i;
            int target=matrix[row][col];
            while(row<n&&col<m)
            {
                if(target!=matrix[row][col])
                    return false;
                row++;
                col++;
            }
        }
        for(int i=0;i<n;i++)
        {
            int row=i,col=0;
            int target=matrix[row][col];
            while(row<n&&col<m)
            {
                if(target!=matrix[row][col])
                    return false;
                row++;
                col++;
            }
        }
        return true;
    }
};