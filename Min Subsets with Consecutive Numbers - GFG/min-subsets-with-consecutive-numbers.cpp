// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int numofsubset(int arr[], int n)
    {
        if(n==1)return n;
        
        sort(arr,arr+n);
        int count=0;
        bool isConseq=false;
        for(int i=1;i<n;i++)
        {
            if(arr[i-1]+1!=arr[i])
            {
                count++;
            }
        }
        if(arr[n-1]!=arr[n-2])count++;
        return count;
    }
    
};

// { Driver Code Starts.
// Driven Program
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n+1];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
        Solution ob;
	    cout << ob.numofsubset(arr, n) << endl;
	}
	return 0;
}
  // } Driver Code Ends