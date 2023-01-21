class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k==0||n>=k+maxPts-1)
            return 1;
        vector<double>dp(n+1,0);
        dp[0]=1;
        double sum=0;
        for(int i=0;i<n;i++)
        {
            if(i<k)
                sum+=dp[i];
            if(i>=maxPts)
                sum-=dp[i-maxPts];
            dp[i+1]=sum/maxPts;
        }
        double ans=0;
        for(int i=k;i<=n;i++)
        {
            ans+=dp[i];
        }
        return ans;
    }
};