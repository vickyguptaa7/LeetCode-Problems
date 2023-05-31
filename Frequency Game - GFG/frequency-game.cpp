//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++)
            freq[arr[i]]++;
        pair<int,int>res={1e9,0};
        for(auto f:freq)
        {
            if(f.second<res.first||(f.second==res.first&&f.first>res.second))
            {
                res={f.second,f.first};
            }
        }
        return res.second;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends