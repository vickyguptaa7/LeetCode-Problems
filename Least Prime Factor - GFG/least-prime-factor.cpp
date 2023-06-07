//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     
    vector<int>findPrimeSieve(int n)
    {
        vector<int>prime_sieve(n+1,1);
        for(int i=2;i<=n;i++)
        {
            if(prime_sieve[i]!=1)
                continue;
            for(long long j=i;j<=n;j+=(i))
            {
                if(prime_sieve[j]==1)
                    prime_sieve[j]=(i);
            }
        }
        return prime_sieve;
    }
    
    vector<int> leastPrimeFactor(int n) {
        vector<int>prime_sieve=findPrimeSieve(n);
        return prime_sieve;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends