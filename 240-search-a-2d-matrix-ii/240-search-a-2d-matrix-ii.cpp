class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size(),cols=matrix[0].size();
        int r=0,c=cols-1;
        
        while(r<rows&&c>=0)
        {
            if(matrix[r][c]==target)
            {
                return true;
            }
            else if(matrix[r][c]>target)
            {
                c--;
            }
            else
            {
                r++;
            }
        }
        return false;
    }
};