class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n));
        int row_s=0,col_s=0,row_e=n-1,col_e=n-1;
        int cntr=1,upto=n*n;
        while(cntr<=upto)
        {
            for(int i=col_s;i<=col_e;i++)
            {
                matrix[col_s][i]=cntr++;
            }
            col_s++;
            for(int i=col_s;i<=row_e;i++)
            {
                matrix[i][col_e]=cntr++;
            }
            col_e--;
            for(int i=col_e;i>=row_s;i--)
            {
                matrix[row_e][i]=cntr++;
            }
            row_e--;
            for(int i=row_e;i>=col_s;i--)
            {
                matrix[i][row_s]=cntr++;
            }
            row_s++;
        }
        return matrix;
    }
};