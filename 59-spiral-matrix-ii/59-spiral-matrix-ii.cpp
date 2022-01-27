class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n));
        int total_num=n*n,curr=1;
        int s_col=0,s_row=0,e_col=n-1,e_row=n-1;
        while(curr<=total_num)
        {
            for(int i=s_row;i<=e_col&&curr<=total_num;i++)
            {
                matrix[s_row][i]=curr++;
            }
            s_row++;
            for(int i=s_row;i<=e_row&&curr<=total_num;i++)
            {
                matrix[i][e_col]=curr++;
            }
            e_col--;
            for(int i=e_col;i>=s_col&&curr<=total_num;i--)
            {
                matrix[e_row][i]=curr++;
            }
            e_row--;
            for(int i=e_row;i>=s_row&&curr<=total_num;i--)
            {
                matrix[i][s_col]=curr++;
            }
            s_col++;
        }
        return matrix;
    }
};