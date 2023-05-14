//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    
    long long helper(int strt,int N,vector<int>&A,vector<long long>&dp)
    {
        if(strt>=N)
            return 0;
        if(dp[strt]!=-1)
            return dp[strt];
        return dp[strt]=A[strt]+max(helper(strt+1,N,A,dp),helper(strt+2,N,A,dp));
    }
  
    long long findMaxSubsetSum(int N, vector<int> &A) {
        // code here
        vector<long long>dp(N,-1);
        return max(helper(0,N,A,dp),helper(1,N,A,dp));
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends