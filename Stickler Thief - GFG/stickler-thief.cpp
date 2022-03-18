// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    
    int helper(int arr[],int s,int n,vector<int>&dp)
    {
        if(s>=n)
        {
            return 0;
        }
        if(dp[s]!=-1)return dp[s];
        
        dp[s]=max(helper(arr,s+1,n,dp),helper(arr,s+2,n,dp)+arr[s]);
        return dp[s];
    }
    
    int FindMaxSum(int arr[], int n)
    {
        if(n==1)return arr[0];
        vector<int>dp(n,-1);
        return helper(arr,0,n,dp);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends