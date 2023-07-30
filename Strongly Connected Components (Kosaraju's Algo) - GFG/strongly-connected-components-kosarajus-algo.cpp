//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
    void dfs(int src,vector<vector<int>>&adj,vector<int>&visited,vector<int>&topoSort)
    {
        visited[src]=true;
        for(auto child:adj[src])
        {
            if(visited[child])continue;
            dfs(child,adj,visited,topoSort);
        }
        topoSort.push_back(src);
    }
    
    void helper(int src,vector<int>adj[],vector<int>&visited)
    {
        visited[src]=true;
        for(auto child:adj[src])
        {
            if(visited[child])continue;
            helper(child,adj,visited);
        }
    }
    
    
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int>topoSort;
        vector<int>visited(V,0);
        for(int i=0;i<V;i++)
        {
            if(visited[i])continue;
            dfs(i,adj,visited,topoSort);
        }
        
        vector<int>rlist[V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<adj[i].size();j++)
                rlist[adj[i][j]].push_back(i);
        }
        int components=0;
        for(auto &x:visited)x=0;
        reverse(topoSort.begin(),topoSort.end());
        for(int i=0;i<topoSort.size();i++)
        {
            if(visited[topoSort[i]])continue;
            components++;
            helper(topoSort[i],rlist,visited);
        }
        return components;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends