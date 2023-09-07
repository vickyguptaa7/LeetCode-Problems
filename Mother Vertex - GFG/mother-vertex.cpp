//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    
    void dfsTopo(int src,vector<int>list[],vector<int>&visited,vector<int>&topo)
    {
        visited[src]=true;
        for(auto child:list[src])
        {
            if(visited[child])
                continue;
            dfsTopo(child,list,visited,topo);
        }
        topo.push_back(src);
    }
    
    void dfs(int src,vector<int>list[],vector<int>&visited,int &rem)
    {
        rem--;
        visited[src]=true;
        for(auto child:list[src])
        {
            if(visited[child])
                continue;
            dfs(child,list,visited,rem);
        }
    }
    
    
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<int>topo,visited(V,0);
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i])continue;
	        dfsTopo(i,adj,visited,topo);
	    }
	   // reverse(topo.begin(),topo.end());
	    fill(visited.begin(),visited.end(),0);
	    int rem=V;
	    dfs(topo.back(),adj,visited,rem);
	    return rem==0?topo.back():-1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends