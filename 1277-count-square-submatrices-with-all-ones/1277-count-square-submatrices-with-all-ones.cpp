class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>preSumMat(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                preSumMat[i][j]+=matrix[i-1][j-1]+
                    preSumMat[i][j-1]+preSumMat[i-1][j]-preSumMat[i-1][j-1];
            }
        }
        int mxSide=min(n,m),sqcount=0;
        for(int side=1;side<=mxSide;side++)
        {
            for(int i=side-1;i<n;i++)
            {
                for(int j=side-1;j<m;j++)
                {
                    int squareSum=preSumMat[i+1][j+1]-
                    preSumMat[i+1][j-side+1]-preSumMat[i-side+1][j+1]+preSumMat[i-side+1][j-side+1];
                    if((side)*(side)==squareSum)
                        sqcount++;
                }
            }
        }
        return sqcount;
    }
};