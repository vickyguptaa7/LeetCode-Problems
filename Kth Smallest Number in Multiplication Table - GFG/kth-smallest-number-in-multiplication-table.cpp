//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int KthSmallest(int m, int n, int k) {
       int low=1,high=n*m,ans=0;
       while(low<=high)
       {
           int mid=(low+high)/2;
           int cnt=0;
           for(int i=1;i<=n;i++)
           {
               cnt+=min(mid/i,m);
           }
           if(cnt>=k)
           {
               ans=mid;
               high=mid-1;
           }
           else
           {
               low=mid+1;
           }
       }
       return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n, k;
	    cin >> m >> n >> k;
	    Solution ob;
	    int ans = ob.KthSmallest(m, n, k);
	    cout << ans << endl;
	}
	return 0;
}

// } Driver Code Ends