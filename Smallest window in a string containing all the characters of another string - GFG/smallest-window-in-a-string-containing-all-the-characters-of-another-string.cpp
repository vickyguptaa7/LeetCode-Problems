//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        vector<int>freq(27,0);
        int isPresent=0;
        int counter=0;
        for(auto x:p)
        {
            freq[x-'a']++;
            isPresent=(isPresent|(1<<(x-'a')));
        }
        counter=__builtin_popcount(isPresent);
        int prev=0,size=1e9,start=-1;
        for(int i=0;i<s.size();i++)
        {
            if(isPresent&(1<<(s[i]-'a')))
            {
                freq[s[i]-'a']--;
                if(freq[s[i]-'a']==0)
                    counter--;
            }
            
            while(counter==0)
            {
                if(size>i-prev+1)
                {
                    size=i-prev+1;
                    start=prev;
                }
                if(isPresent&(1<<(s[prev]-'a')))
                {
                    freq[s[prev]-'a']++;
                    if(freq[s[prev]-'a']==1)
                        counter++;
                }
                prev++;
            }
        }
        if(start==-1)
            return "-1";
        return s.substr(start,size);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends