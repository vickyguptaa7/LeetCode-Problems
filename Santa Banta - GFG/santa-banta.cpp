//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    int* prime;
    void precompute(){
        prime=new int[1000001];
        for(int i=0;i<=1e6;i++)prime[i]=1;
        for(long long i=2;i<=1e6;i++)
        {
            for(long long j=i*i;j<1e6;j+=i)
            {
                prime[j]=0;
            }
        }
    }
    int helper(int src,vector<vector<int>>&list,vector<int>&visit)
    {
        visit[src]=true;
        int cnt=1;
        for(auto child:list[src])
        {
            if(visit[child])
                continue;
            cnt+=helper(child,list,visit);
        }
        return cnt;
    }
    int helpSanta(int n, int m, vector<vector<int>> &g){
        vector<int>visit(n+1,0);
        int mxCon=0;
        for(int i=1;i<=n;i++)
        {
            if(visit[i])continue;
            mxCon=max(mxCon,helper(i,g,visit));
        }
        if(mxCon==1)
            return -1;
        for(int i=2;i<=1e6;i++)
        {
            if(prime[i])
            {
                mxCon--;
                if(mxCon==0)
                    return i;
            }
        }
        return mxCon;
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends