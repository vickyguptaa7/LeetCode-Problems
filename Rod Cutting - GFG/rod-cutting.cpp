//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int helper(int n,int prices[],vector<int>&dp)
    {
        if(dp[n]!=-1)
            return dp[n];
        int cost=0;
        for(int i=0;i<n;i++)
        {
            cost=max(cost,prices[i]+helper(n-1-i,prices,dp));
        }
        return dp[n]=cost;
    }
    int cutRod(int price[], int n) {
        vector<int>dp(n+2,-1);
        return helper(n,price,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends