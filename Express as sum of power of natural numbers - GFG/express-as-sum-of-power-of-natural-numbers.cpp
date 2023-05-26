//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    
    int helper(int strt,int n,int x,vector<vector<int>>&dp)
    {
        if(n==0)
            return 1;
        if(n<0||strt==n+1)
            return 0;
        
        if(dp[strt][n]!=-1)
            return dp[strt][n];
        
        int mod=1e9+7;
        if(pow(strt,x)<=n)
        {
            return dp[strt][n]=(helper(strt+1,n-pow(strt,x),x,dp)+(long long)helper(strt+1,n,x,dp))%mod;
        }
        else 
        {
            return dp[strt][n]=0;
        }
    }
    
    int numOfWays(int n, int x)
    {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(1,n,x,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends