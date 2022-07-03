// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> primeRange(int M, int N) {
        vector<int>sieve(N+1,0);
        sieve[1]=1;
        for(long long i=2;i<=N;i++)
        {
            for(long long j=i*i;j<=N;j+=i)
            {
                sieve[j]++;
            }
        }
        vector<int>ans;
        for(int i=M;i<=N;i++)
        {
            if(sieve[i]==0)ans.push_back(i);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}  // } Driver Code Ends