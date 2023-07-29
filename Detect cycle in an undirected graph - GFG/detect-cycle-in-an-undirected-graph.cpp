//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    bool helper(int src,int par,vector<int>list[],vector<int>&visited)
    {
        visited[src]=true;
        for(auto child:list[src])
        {
            if(visited[child])
            {
                if(child!=par)
                    return true;
                continue;
            }
            
            if(helper(child,src,list,visited))
                return true;
        }
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>visited(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i]&&helper(i,-1,adj,visited))
                return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends