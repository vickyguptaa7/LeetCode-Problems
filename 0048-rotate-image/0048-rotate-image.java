class Solution {
    public void rotate(int[][] matrix) {
                int n=matrix.length,m=matrix[0].length;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int temp = matrix[j][i];
                matrix[j][i]=matrix[i][j];
                matrix[i][j]=temp;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m/2;j++)
            {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[i][m-1-j];
                matrix[i][m-1-j]=temp;
            }
        }
    }
}