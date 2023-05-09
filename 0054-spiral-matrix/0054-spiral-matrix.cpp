class Solution
{
    public:
        vector<int> spiralOrder(vector<vector < int>> &matrix)
        {
            vector<int> result;
            int left = 0, right = (int) matrix[0].size() - 1, top = 0, bottom = (int) matrix.size() - 1;
            int total = matrix[0].size() *matrix.size();
            while (total)
            {
                for (int i = left; i <= right&&total; i++)
                {
                    result.push_back(matrix[top][i]);
                    total--;
                }
                top++;
                for (int i = top; i <= bottom&&total; i++)
                {
                    result.push_back(matrix[i][right]);
                    total--;
                }
                right--;
                for (int i = right; i >= left&&total; i--)
                {
                    result.push_back(matrix[bottom][i]);
                    total--;
                }
                bottom--;
                for (int i = bottom; i >= top&&total; i--)
                {
                    result.push_back(matrix[i][left]);
                    total--;
                }
                left++;
            }
            return result;
        }
};