class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>pque;
        int rows=matrix.size(),cols=matrix[0].size();
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(pque.size()<k)
                {
                    pque.push(matrix[i][j]);
                }
                else
                {
                    if(pque.top()>matrix[i][j])
                    {
                        pque.pop();
                        pque.push(matrix[i][j]);
                    }
                }
            }
        }
        return pque.top();
    }
};