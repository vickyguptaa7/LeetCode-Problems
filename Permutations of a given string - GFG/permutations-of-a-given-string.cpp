//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    vector<string>result;
		    sort(S.begin(),S.end());
		    helper(0,"",S,result);
		    
		    return result;
		}
		
		void helper(int strt,string perm,string&str,vector<string>&result)
		{
		    if(strt==str.size())
		    {
		        result.push_back(perm);
		        return;
		    }
		    for(int i=0;i<str.size();i++)
		    {
		        if(i>0&&str[i-1]==str[i])continue;
		        char temp=str[i];
		        str.erase(i,1);
		        helper(strt,perm+temp,str,result);
		        str.insert(str.begin()+i,temp);
		    }
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends