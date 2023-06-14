//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long maxDiamonds(int A[], int N, int K) {
        long long maxD=0;;
        priority_queue<int>pque;
        for(int i=0;i<N;i++)pque.push(A[i]);
        while(K--&&!pque.empty())
        {
            int d=pque.top();
            pque.pop();
            maxD+=d;
            if(d/2)
                pque.push(d/2);
        }
        return maxD;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends