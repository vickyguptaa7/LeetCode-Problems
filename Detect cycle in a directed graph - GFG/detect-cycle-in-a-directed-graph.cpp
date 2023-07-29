//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    int helper(int src,vector<int>list[],vector<int>&visited,vector<int>&recurVisited)
    {
        visited[src]=true;
        recurVisited[src]=true;
        for(auto child:list[src])
        {
            if(visited[child])
            {
                if(recurVisited[child])
                    return true;
                continue;
            }
            if(helper(child,list,visited,recurVisited))
                return true;
        }
        recurVisited[src]=false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>visited(V,0);
        vector<int>recurVisited(V,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i]&&helper(i,adj,visited,recurVisited))
                return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends