class Solution {
public:
    void Transpose(vector<vector<int>>&matrix)
    {
        int n=matrix.size();
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    void Reverse_Row(vector<vector<int>>&matrix)
    {
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].begin()+n);
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        Transpose(matrix);
        Reverse_Row(matrix);
    }
};