class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>preMat(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                preMat[i][j]=mat[i-1][j-1]+preMat[i-1][j]+preMat[i][j-1]
                    -preMat[i-1][j-1];
            }
        }
        vector<vector<int>>answer(n,vector<int>(m,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int topLeftR=max(1,i-k),bottomRightR=min(n,i+k);
                int topLeftC=max(1,j-k),bottomRightC=min(m,j+k);
                answer[i-1][j-1]=preMat[bottomRightR][bottomRightC]+
                    +preMat[topLeftR-1][topLeftC-1]-
                    preMat[topLeftR-1][bottomRightC]-
                    preMat[bottomRightR][topLeftC-1];
            }
        }
        return answer;
    }
};