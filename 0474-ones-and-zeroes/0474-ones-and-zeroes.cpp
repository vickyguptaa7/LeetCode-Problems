class Solution {
    int dp[600][101][101];
    vector<string>arr;
public:
    int helper(int indx,int n,int m)
    {
        if(indx==arr.size()||n<0||m<0)
            return 0;
        
        if(dp[indx][n][m]!=-1)
            return dp[indx][n][m];
        
        int oc=0,zc=0;
        for(auto x:arr[indx])
            if(x=='1')oc++;
            else zc++;
        
        int res=helper(indx+1,n,m);
        
        if(oc<=m&&zc<=n)
        {
            res=max(1+helper(indx+1,n-zc,m-oc),res);
        }
        
        return dp[indx][n][m]=res;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        arr=strs;
        return helper(0,m,n);
    }
};