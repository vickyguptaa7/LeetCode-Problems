// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int count(int N){
        // code here
        if(N%2)return false;
        if(N==0)return 1;
        
        int sum=0;
        for(int i=2;i<=N;i++)
        {
            int left=count(i-2);
            int right=count(N-i);
            sum+=left*right;
        }
        return sum;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends