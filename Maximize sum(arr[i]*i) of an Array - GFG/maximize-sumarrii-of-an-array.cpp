// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int Maximize(int arr[],int n)
    {
        sort(arr,arr+n);
        long long mod=1e9+7;
        long long ans=0;
        for(long long i=0;i<n;i++)
        {
            ans+=i*arr[i];
            ans%=mod;
        }
        return int(ans);
    }
};

// { Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}  // } Driver Code Ends