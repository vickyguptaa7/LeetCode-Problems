//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isPossible(long long a[], long long b[], int n, long long k) {
        map<long long,long long>freq;
        for(int i=0;i<n;i++)
        {
            freq[a[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            auto itr=freq.lower_bound(k-b[i]);
            if(itr==freq.end())return false;
            freq[itr->first]--;
            if(freq[itr->first]==0)
            {
                freq.erase(itr->first);
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        long long a[n + 2], b[n + 2];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        Solution ob;
        cout << ob.isPossible(a, b, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends