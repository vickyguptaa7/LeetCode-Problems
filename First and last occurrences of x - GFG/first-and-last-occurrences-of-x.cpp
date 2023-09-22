//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int firstOccurence(int arr[],int n,int x)
    {
        int low=0,high=n-1,ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]>=x)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans==-1?-1:arr[ans]!=x?-1:ans;
    }
    
    int lastOccurence(int arr[],int n,int x)
    {
        int low=0,high=n-1,ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]<=x)
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans==-1?-1:arr[ans]!=x?-1:ans;
    }
    
    public:
    vector<int> find(int arr[], int n , int x )
    {
        return {firstOccurence(arr,n,x),lastOccurence(arr,n,x)};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends