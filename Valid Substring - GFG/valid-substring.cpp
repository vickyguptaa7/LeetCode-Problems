// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        int lc=0,rc=0,res=0,n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')lc++;
            else rc++;
            
            if(rc>lc)
            {
                lc=0;
                rc=0;
            }
            if(lc==rc)
            {
                res=max(res,2*lc);
            }

        }
        lc=0,rc=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='(')lc++;
            else rc++;
            if(rc<lc)
            {
                lc=0;
                rc=0;
            }
            if(lc==rc)
            {
                res=max(res,2*lc);
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends