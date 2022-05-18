class Solution {
public:
    void dfs(vector<int>adj[],int node,int parent,vector<vector<int>>&ans,vector<int>&timins, vector<int>&low,vector<bool>&vis,int &timer)
    {
        vis[node]=1;
        timins[node]=low[node]=timer++;
        for(auto it:adj[node])
        {
            if(it==parent)
                continue;
            if(vis[it]==0)
            {
                dfs(adj,it,node,ans,timins,low,vis,timer);
                low[node]=min(low[node],low[it]);
                if(low[it]>timins[node])
                {
                    vector<int>v;
                    v.push_back(node);
                    v.push_back(it);
                    ans.push_back(v);
                }
            }
            else
                low[node]=min(low[node],timins[it]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        vector<vector<int>>ans;
        vector<int>adj[n];
        for(int i=0;i<connections.size();i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>timins(n,-1);
        vector<int>low(n,-1);
        vector<bool>vis(n,0);
        int timer=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                dfs(adj,i,-1,ans,timins,low,vis,timer);
            }
        }
        return ans;
    }
};