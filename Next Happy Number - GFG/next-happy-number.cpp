//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int nextHappy(int N){
        for(int i=N+1;i<=1e5;i++)
        {
            int temp=i;
            set<int>oset;
            while(temp!=1)
            {
                int help=0;
                while(temp)
                {
                    help+=(temp%10)*(temp%10);
                    temp/=10;
                }
                temp=help;
                if(oset.count(temp))
                    break;
                oset.insert(temp);
            }
            if(temp==1)
                return i;
        }
        return 0;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends