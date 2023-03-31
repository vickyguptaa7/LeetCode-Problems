class Solution
{
    public:
        vector<vector<int>>findPreSumMatrix(vector<string>&pizza)
        {
            int r = pizza.size(), c = pizza[0].size();
            vector<vector<int>>preSum(r + 1, vector<int> (c + 1, 0));
            for (int i = 1; i <= r; i++)
            {
                for (int j = 1; j <= c; j++)
                {
                    preSum[i][j] += (pizza[i - 1][j - 1] == 'A') ? 1 + preSum[i][j - 1] : preSum[i][j - 1];
                }
            }
            for (int i = 1; i <= c; i++)
            {
                for (int j = 1; j <= r; j++)
                {
                    preSum[j][i] += preSum[j - 1][i];
                }
            }
            return preSum;
        }
    int preSumCalc(int ulx,int uly,int brx,int bry,vector<vector<int>>&preSumMat)
    {
        // cout<<ulx<<" "<<uly<<" "<<brx<<" "<<bry<<"\n";
        //cout<<preSumMat[brx][bry]<<" "<<preSumMat[brx][uly]<<
        //" "<<preSumMat[ulx][bry]<<" "<<preSumMat[ulx][bry]<<"\n";
        // upper left x | upper right y | bottom right x | bottom right y 
        return preSumMat[brx][bry]-preSumMat[brx][uly]-preSumMat[ulx][bry]+preSumMat[ulx][uly];
    }
    
    int waysHelper(int x,int y,int r,int c,int k,vector<vector<int>>&preSumMat,vector<vector<vector<int>>>&dp)
    {
        if(k==1)
            return 1;
        if(dp[x][y][k]!=-1)
            return dp[x][y][k];
        
        long long ways=0,mod=1e9+7;
        for(int div=x+1;div<r;div++)
        {
            if(preSumCalc(x,y,div,c,preSumMat)&&preSumCalc(div,y,r,c,preSumMat))
                ways+=waysHelper(div,y,r,c,k-1,preSumMat,dp),ways%=mod;
        }
        for(int div=y+1;div<c;div++)
        {
            if(preSumCalc(x,y,r,div,preSumMat)&&preSumCalc(x,div,r,c,preSumMat))
                ways+=waysHelper(x,div,r,c,k-1,preSumMat,dp),ways%=mod;
        }
        return dp[x][y][k]=ways;
    }
    
    int ways(vector<string>&pizza, int k)
    {
        int r = pizza.size(), c = pizza[0].size();
        vector<vector<int>>preSumMat=findPreSumMatrix(pizza);
        vector<vector<vector<int>>>dp(r+1,vector<vector<int>>(c+1,vector<int>(k+1,-1)));
        return waysHelper(0,0,r,c,k,preSumMat,dp);
    }
};