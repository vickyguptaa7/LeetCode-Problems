//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
    
        void merge(int arr[],int strt,int mid,int end)
        {
            int size=end-strt+1;
            vector<int>helper(size);
            int left=strt,right=mid+1,iter=0;
            while(left<=mid&&right<=end)
            {
                if(arr[left]<0)
                {
                    helper[iter]=arr[left];
                    iter++;
                    left++;
                }
                else if(arr[right]<0)
                {
                    helper[iter]=arr[right];
                    right++;
                    iter++;
                }
                else
                {
                    helper[iter]=arr[left]++;
                    left++;
                    iter++;
                }
            }
            while(left<=mid)
            {
                helper[iter]=arr[left]++;
                left++;
                iter++;
            }
            while(right<=end)
            {
                helper[iter]=arr[right];
                right++;
                iter++;
            }
            for(int i=strt;i<=end;i++)
            {
                arr[i]=helper[i-strt];
            }

        }
        
        void merge_sort(int arr[],int strt,int end)
        {
            if(strt>=end)
                return;
            int mid=(strt+end)/2;
            merge_sort(arr,strt,mid);
            merge_sort(arr,mid+1,end);
            merge(arr,strt,mid,end);
        }
        
        void Rearrange(int arr[], int n)
        {
            merge_sort(arr,0,n-1);
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends