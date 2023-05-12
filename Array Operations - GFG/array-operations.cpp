//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        if(find(arr.begin(),arr.end(),0)==arr.end())
            return -1;
        int start=-1,cntr=1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=0)
            {
                start=i;
                break;
            }
        }
        if(start==-1)
            return 0;
        for(int i=start;i<n;i++)
        {
            if(arr[i]==0)
            {
                if(i>0&&arr[i-1]==arr[i])
                    continue;
                cntr++;
            }
        }
        return arr.back()==0?cntr-1:cntr;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends