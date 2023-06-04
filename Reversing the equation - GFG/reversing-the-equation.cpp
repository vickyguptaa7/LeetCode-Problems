//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            stack<char>st;
            string res;
            for(int i=0;i<s.size();i++)
            {
                if(s[i]>='0'&&s[i]<='9')
                {
                    st.push(s[i]);
                }
                else 
                {
                    while(!st.empty())
                    {
                        res+=st.top();
                        st.pop();
                    }
                    res+=s[i];
                }
            }
                    while(!st.empty())
                    {
                        res+=st.top();
                        st.pop();
                    }
            reverse(res.begin(),res.end());
            return res;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends