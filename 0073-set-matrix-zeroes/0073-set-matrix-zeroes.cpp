class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isFRowZero=false,isFColZero=false;
        int n=matrix.size(),m=matrix[0].size();
        // check for first row zero
        for(int i=0;i<m;i++)
        {
            if(!matrix[0][i])
            {
                isFRowZero=true;
                break;
            }
        }
        // check for first col zero
        for(int i=0;i<n;i++)
        {
            if(!matrix[i][0])
            {
                isFColZero=true;
                break;
            }
        }
        
        // check for rest of the rows zero
        for(int i=1;i<n;i++)
        {
            bool isZeroPresent=true;
            for(int j=0;j<m;j++)
            {
                if(!matrix[i][j])
                {
                    isZeroPresent=false;
                    break;
                }
            }
            if(!isZeroPresent)
                matrix[i][0]=isZeroPresent;
        }
        
        // check for the rest of the cols zero
        for(int i=1;i<m;i++)
        {
            bool isZeroPresent=true;
            for(int j=0;j<n;j++)
            {
                if(!matrix[j][i])
                {
                    isZeroPresent=false;
                    break;
                }
            }
            if(!isZeroPresent)
                matrix[0][i]=isZeroPresent;
        }
        
        // mark row with zero
        for(int i=1;i<n;i++)
        {
            if(matrix[i][0])continue;
            for(int j=0;j<m;j++)
            {
                matrix[i][j]=0;
            }
        }
        
        // mark col with zero
        for(int i=1;i<m;i++)
        {
            if(matrix[0][i])continue;
            for(int j=0;j<n;j++)
            {
                matrix[j][i]=0;
            }
        }
        
        // mark first row and col with zero 
        if(isFColZero)
            for(int i=0;i<n;i++)
            {
                // cout<<matrix[i][0]<<" ";
                matrix[i][0]=0;
            }
        // cout<<"\n";
        if(isFRowZero)
            for(int i=0;i<m;i++)
            {
                // cout<<matrix[0][i]<<" ";
                matrix[0][i]=0;
            }
        // cout<<"\n";
        
    }
};