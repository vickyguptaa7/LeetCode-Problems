class NumMatrix
{
    public:
        vector<vector < int>>  preSumX;
    NumMatrix(vector<vector < int>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        for (int i = 0; i < rows; i++)
        {
            int sum = 0;
            vector<int> row = { 0 };
            for (int j = 0; j < cols; j++)
            {
                sum += matrix[i][j];
                row.push_back(sum);
            }
            preSumX.push_back(row);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
        for(int i=row1;i<=row2;i++)
        {
            ans+=preSumX[i][col2+1]-preSumX[i][col1];
        }
        return ans;
    }
};

/**
 *Your NumMatrix object will be instantiated and called as such:
 *NumMatrix* obj = new NumMatrix(matrix);
 *int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */