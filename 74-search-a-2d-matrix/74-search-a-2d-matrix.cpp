class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0,high=matrix.size()*matrix[0].size()-1;
        int cols=matrix[0].size();
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int r=mid/cols,c=mid%cols;
            
            if(matrix[r][c]==target)
            {
                return true;
            }
            else if(matrix[r][c]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return false;
    }
};