//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        // Code here
        string res;
        res+=str[0];
        if(str.size()>1&&str[0]==str[1])
        {
            return res+res;
        }
        for(int i=1;i<str.size();i++)
        {
            if(str[i]<=str[i-1])
            {
                res+=str[i];
            }
            else 
                break;
        }
        string temp=res;
        reverse(temp.begin(),temp.end());
        return res+temp;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends