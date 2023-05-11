//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int minimumSum(string s) {
        int n=s.size();
        vector<int>indx;
        for(int i=0;i<(n+1)/2;i++)
        {
            if(s[i]!='?'||s[n-1-i]!='?')
            {
                if(s[i]!='?'&&s[n-1-i]!='?'&&(s[i]!=s[n-1-i]))
                    return -1;
                if(s[i]=='?')s[i]=s[n-1-i];
                if(s[n-1-i]=='?')s[n-1-i]=s[i];
            }
        }
        char start;

        for(int i=0;i<(n)/2;i++)
        {
            if(s[i]!='?')
            {
                start=s[i];
                break;
            }
        }
        int score=0;
        for(int i=0;i<(n)/2;i++)
        {
            if(s[i]!='?')
            {
                start=s[i];
                score+=(i>0)?abs(s[i]-s[i-1]):0; 
                continue;
            }
            s[i]=start;
            s[n-1-i]=start;
            score+=(i>0)?abs(s[i]-s[i-1]):0; 
        }
        return score*2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends