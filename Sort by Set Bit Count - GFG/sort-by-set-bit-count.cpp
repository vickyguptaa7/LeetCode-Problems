// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

int bitCount(int a)
{
    int c=0;
    while(a)
    {
        a=((a-1)&a);
        c++;
    }
    return c;
}

bool mycomp(int a,int b)
{
    return bitCount(a)>bitCount(b);
}
class Solution{
    public:
    void sortBySetBitCount(int arr[], int n)
    {
        stable_sort(arr,arr+n,mycomp);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends