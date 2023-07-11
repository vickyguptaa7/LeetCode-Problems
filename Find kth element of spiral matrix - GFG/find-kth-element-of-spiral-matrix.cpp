//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		int left=0,right=m-1;
 		int top=0,bottom=n-1;
 		int val=0;
 		while(k)
 		{
 		    for(int i=left;i<=right&&k;i++)
 		    {
 		        k--;
 		        val=a[top][i];
 		    }
 		    top++;
 		    for(int i=top;i<=bottom&&k;i++)
 		    {
 		        k--;
 		        val=a[i][right];
 		    }
 		    right--;
 		    for(int i=right;i>=left&&k;i--)
 		    {
 		        k--;
 		        val=a[bottom][i];
 		    }
 		    bottom--;
 		    for(int i=bottom;i>=top&&k;i--)
 		    {
 		        k--;
 		        val=a[i][left];
 		    }
 		    left++;
 		}
 		return val;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends