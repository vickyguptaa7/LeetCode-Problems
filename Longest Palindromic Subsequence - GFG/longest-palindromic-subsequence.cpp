//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
    int lcs(int i1,int i2,string &A,string &B,vector<vector<int>>&dp)
    {
        if(i1==A.size()||i2==B.size())
            return 0;
            
        if(dp[i1][i2]!=-1)
            return dp[i1][i2];
            
        if(A[i1]==B[i2])
            return dp[i1][i2]=1+lcs(i1+1,i2+1,A,B,dp);
        else
            return dp[i1][i2]=max(lcs(i1+1,i2,A,B,dp),lcs(i1,i2+1,A,B,dp));
    }
  
    int longestPalinSubseq(string A) {
        string revA=A;
        reverse(revA.begin(),revA.end());
        int n=A.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return lcs(0,0,A,revA,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends