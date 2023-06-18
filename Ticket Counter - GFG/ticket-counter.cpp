//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        int left=1,right=N;
        bool isFirst=true;
        while(left<=right)
        {
            if(right-left+1>=K)
            {
                if(isFirst)
                {
                    left+=K;
                }
                else 
                {
                    right-=K;
                }
            }
            else
            {
                if(isFirst)
                {
                    return right;
                }
                else
                {
                    return left;
                }
            }
            isFirst=!isFirst;
        }
        return !isFirst?right:left;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends