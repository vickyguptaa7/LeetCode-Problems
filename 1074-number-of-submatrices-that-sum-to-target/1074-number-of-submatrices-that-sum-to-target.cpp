class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size(),cols=matrix[0].size();
        vector<vector<int>>preSum(rows,vector<int>(cols+1,0));
        for(int i=0;i<rows;i++)
        {
            int sum=0;
            for(int j=1;j<=cols;j++)
            {
                sum+=matrix[i][j-1];
                preSum[i][j]=sum;
            }
        }
        map<int,int>omap;
        int res=0;
        for(int i=1;i<=cols;i++)
        {
            for(int j=i;j<=cols;j++)
            {
                omap[0]=1;
                int curr=0;
                for(int k=0;k<rows;k++)
                {
                    curr+=preSum[k][j]-preSum[k][i-1];
                    res+=omap[curr-target];
                    omap[curr]++;
                }
                omap.clear();
            }
        }
        return res;
    }
};