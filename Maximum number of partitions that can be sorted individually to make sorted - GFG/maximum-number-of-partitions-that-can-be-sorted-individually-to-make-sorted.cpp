//{ Driver Code Starts

// CPP program to find Maximum number of partitions
// such that we can get a sorted array.
#include <bits/stdc++.h>
using namespace std;

// Function to find maximum partitions.
int maxPartitions(int arr[], int n);


// Driver code
int main()
{
	int t,n;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout << maxPartitions(arr, n)<<endl;
    }

	return 0;
}

// } Driver Code Ends


int maxPartitions(int arr[], int n)
{
    // Complete the function
    vector<int>left(n,0),right(n,0);
    int Max=0,Min=1e6;
    for(int i=0;i<n;i++)
    {
        Max=max(arr[i],Max);
        left[i]=Max;
    }
    for(int i=n-1;i>=0;i--)
    {
        Min=min(arr[i],Min);
        right[i]=Min;
    }
    int count=1;
    for(int i=0;i<n-1;i++)
    {
        if(left[i]<=right[i+1])
            count++;
    }
    return count;
}