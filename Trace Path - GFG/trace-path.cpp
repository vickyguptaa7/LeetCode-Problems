//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        int xmn=0,xmx=0,ymn=0,ymx=0,x=0,y=0;
        for(auto ch:s)
        {
            if(ch=='L')
            {
                x--;
            }
            else if(ch=='R')
            {
                x++;
            }
            else if(ch=='U')
            {
                y--;
            }
            else 
            {
                y++;
            }
            xmn=min(xmn,x);
            xmx=max(xmx,x);
            ymn=min(ymn,y);
            ymx=max(ymx,y);
        }
        
        if(xmx-xmn>=m||ymx-ymn>=n)
            return false;
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends