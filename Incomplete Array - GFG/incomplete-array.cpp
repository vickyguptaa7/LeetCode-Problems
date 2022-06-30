// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int countElements(int N, int A[]) {
        int Max=*max_element(A,A+N);
        int Min=*min_element(A,A+N);
        set<int>oset(A,A+N);
        int res=Max-Min-1-(int)oset.size()+2;
        if(res<=0)return 0;
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];
        Solution ob;
        cout << ob.countElements(N, A) << "\n";
    }
}  // } Driver Code Ends