class Solution {
public:
vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>>res;
        int rows=matrix.size(),cols=matrix[0].size();
        for(int i=0;i<cols;i++)
        {
            vector<int>row;
            for(int j=0;j<rows;j++)
            {
                row.push_back(matrix[j][i]);
            }
            res.push_back(row);
        }
        return res;
    }
};