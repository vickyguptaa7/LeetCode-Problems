//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    int product(int a,int b,int mod)
    {
        return (a*1ll*b)%mod;
    }
    
    int add(int a,int b,int mod=1e9+7)
    {
        return (a+0ll+b)%mod;
    }
    
    int diff(int a,int b,int mod=1e9+7)
    {
        return ((a-b+0ll)%mod+mod)%mod;
    }
    
    int power(int a,int b,int mod)
    {
        if(b==0)
            return 1;
                    
        int result=power(a,b/2,mod);
        if(b&1)
        {
            return product(a,product(result,result,mod),mod);
        }
        else 
        {
            return product(result,result,mod);
        }
    }
    
    bool check(string& haystack,string &needle,int indx)
    {
        for(int i=0;i<needle.size();i++)
        {
            if(haystack[i+indx]!=needle[i])
            {
                return false;
            }
        }
        return true;
    }
    public:
        vector <int> search(string needle, string haystack)
        {
             int nhash=0,prime=101,mod=1e9+7,hhash=0;
        int nsize=needle.size(),hsize=haystack.size();
        if(nsize>hsize)
            return {-1};
        for(int i=0;i<nsize;i++)
        {
            nhash=add(nhash,product(needle[i]-'a',power(prime,nsize-i,mod),mod));
            hhash=add(hhash,product(haystack[i]-'a',power(prime,nsize-i,mod),mod));
        }
    
        vector<int>result;
        if(nhash==hhash&&check(haystack,needle,0))
        {
            result.push_back(1);
        }
        for(int i=nsize;i<hsize;i++)
        {
            hhash=diff(hhash,product(haystack[i-nsize]-'a',power(prime,nsize,mod),mod));
            hhash=add(hhash,haystack[i]-'a',mod);
            hhash=product(hhash,prime,mod);
            // cout<<hhash<<" "<<nhash<<'\n';
            if(hhash==nhash&&check(haystack,needle,i-nsize+1))
            {
                result.push_back(i-nsize+2);
            }
        }
        if(result.empty())
        return {-1};
        return result;
        
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends