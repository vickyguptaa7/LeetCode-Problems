//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int modulo(string s,int m)
        {
            int twop=1,n=s.size(),result=0;
            for(int i=0;i<n;i++)
            {
                if(s[n-1-i]=='1')
                {
                    result+=twop;
                    result%=m;
                }
                twop*=2;
                twop%=m;
            }
            return result;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends