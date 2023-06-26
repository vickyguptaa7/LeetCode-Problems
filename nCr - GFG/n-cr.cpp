//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
typedef long long ll;

class Solution{

public:
ll sum(ll a, ll b, ll mod = 1e9 + 7)
{
    return (a + b) % mod;
}

ll diff(ll a, ll b, ll mod = 1e9 + 7)
{
    return ((a - b) % mod + mod) % mod;
}

ll product(ll a, ll b, ll mod = 1e9 + 7)
{
    return (((ll)a % mod) * ((ll)b % mod)) % mod;
}

ll power(ll a, ll b, ll mod = 1e9 + 7)
{
    ll result = 1;
    while (b != 0)
    {
        if (b & 1)
            result = product(result, a, mod);
        a = product(a, a, mod);
        b /= 2;
    }
    return result;
}

ll division(ll a, ll b, ll mod = 1e9 + 7)
{
    return (product(a, power(b, mod - 2, mod), mod));
}

ll factorial(ll a)
{
    ll fact=1;
    for(int i=2;i<=a;i++)fact=product(i,fact);
    return fact;
}
    
    int nCr(int n, int r){
        if(r>n)return 0;
        return division(factorial(n),product(factorial(n-r),factorial(r)));
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends