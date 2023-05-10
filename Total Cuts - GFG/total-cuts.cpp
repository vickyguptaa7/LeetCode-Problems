//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        vector<int>rightMin(N);
        int rmin=A[N-1];
        for(int i=0;i<N;i++)
        {
            rmin=min(rmin,A[N-i-1]);
            rightMin[N-i-1]=rmin;
        }
        int lmax=A[0],result=0;
        for(int i=0;i<N-1;i++)
        {
            lmax=max(lmax,A[i]);
            if(lmax+rightMin[i+1]>=K)
                result++;
        }
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends