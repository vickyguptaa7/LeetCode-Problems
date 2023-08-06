//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void helper(string &s,string &perm,vector<string>&allperm)
    {
        if(s.empty())
        {
            allperm.push_back(perm);
            return;
        }
        
        for(int i=0;i<s.size();i++)
        {
            perm.push_back(s[i]);
            s.erase(s.begin()+i);
            helper(s,perm,allperm);
            s.insert(s.begin()+i,perm.back());
            perm.pop_back();
        }
    }
    
    vector<string> permutation(string S)
    {
        vector<string>allperm;
        string perm;
        helper(S,perm,allperm);
        sort(allperm.begin(),allperm.end());
        return allperm;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends