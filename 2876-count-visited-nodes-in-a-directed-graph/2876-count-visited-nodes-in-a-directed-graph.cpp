class Solution {
public:
    
    int helper(int src,vector<int>&edges,vector<int>&visited,vector<int>&rvisited,vector<int>&cnt,int node,bool& isCycle)
    {
        visited[src]=true;
        rvisited[src]=true;
        
        if(visited[edges[src]])
        {
            if(rvisited[edges[src]])
            {
                isCycle=true;
                cnt[src]=node+cnt[edges[src]];
            }
            else
            {
                cnt[src]=1+cnt[edges[src]];
            }
            rvisited[src]=false;
            return cnt[src];
        }
        int val=1+helper(edges[src],edges,visited,rvisited,cnt,node+1,isCycle)-isCycle;
        rvisited[src]=false;
        
        return cnt[src]=val;
    }
    
    void findTopo(int src,vector<int>&edges,vector<int>&visited,vector<int>&topo)
    {
        if(visited[src])return;
        visited[src]=true;
        int child=edges[src];
        findTopo(child,edges,visited,topo);
        topo.push_back(src);
    }
    
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n=edges.size();
        vector<int>cnt(n,0),visited(n,0),rvisited(n,0);
        vector<int>topo;
        
        for(int i=0;i<n;i++)
        {
            if(visited[i])continue;
            findTopo(i,edges,visited,topo);
        }
        for(auto &x:visited)x=0;
        
        for(int i=0;i<n;i++)
        {
            // cout<<topo[i]<<" ";
            if(visited[topo[i]])continue;
            bool isCycle=false;
            helper(topo[i],edges,visited,rvisited,cnt,1,isCycle);
        }
        return cnt;
    }
};