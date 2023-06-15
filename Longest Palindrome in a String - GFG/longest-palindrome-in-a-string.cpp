//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    string isPalindrome(string &s,int left,int right)
    {
        int n=s.size();
        while(left>=0&&right<n&&s[left]==s[right])
        {
            left--;
            right++;
        }
        // cout<<left<<" "<<right<<"\n";
        return s.substr(left+1,right-left-1);
    }
    
    string longestPalin (string S) {
        int n=S.size();
        string res;
        res+=S[0];
        for(int i=1;i<n;i++)
        {
            string temp=isPalindrome(S,i-1,i);
            // cout<<temp<<"\n";
            if(temp.size()>res.size())
            {
                res=temp;
            }
            temp=isPalindrome(S,i,i);
            if(temp.size()>res.size())
            {
                res=temp;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends