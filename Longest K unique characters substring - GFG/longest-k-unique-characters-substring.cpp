//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        map<char,int>freq;
        int prev=0,longest=-1;
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]]++;
            while(freq.size()>k)
            {
                freq[s[prev]]--;
                if(freq[s[prev]]==0)
                    freq.erase(s[prev]);
                prev++;
            }
            if(freq.size()==k)
            {
                longest=max(longest,i-prev+1);
            }
        }
        return longest;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends