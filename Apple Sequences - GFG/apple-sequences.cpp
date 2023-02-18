//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        int maxLen=0,prev=0;
        for(int i=0;i<n;i++)
        {
            m-=(arr[i]=='O')?1:0;
            while(m<0)
            {
                m+=(arr[prev]=='O')?1:0;
                prev++;
            }
            maxLen=max(maxLen,i-prev+1);
        }
        return maxLen;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends