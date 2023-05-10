class Solution
{
    public:
        vector<vector < int>> generateMatrix(int n)
        {
            vector<vector<int>> result(n,vector<int>(n,0));
            int left = 0, right = (int) n - 1, top = 0, bottom = (int) n - 1;
            int total = n*n,iter=1;
            while (total)
            {
                for (int i = left; i <= right && total; i++)
                {
                    result[top][i]=iter++;
                    total--;
                }
                top++;
                for (int i = top; i <= bottom && total; i++)
                {
                    result[i][right]=iter++;
                    total--;
                }
                right--;
                for (int i = right; i >= left && total; i--)
                {
                    result[bottom][i]=iter++;
                    total--;
                }
                bottom--;
                for (int i = bottom; i >= top && total; i--)
                {
                    result[i][left]=iter++;
                    total--;
                }
                left++;
            }
            return result;
        }
};