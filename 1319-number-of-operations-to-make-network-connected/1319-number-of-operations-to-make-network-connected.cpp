class Solution {
public:
    
    void dfs(int src,vector<int>&visit,vector<int>list[],int &edges,int &nodes)
    {
        visit[src]=true;
        nodes++;
        for(auto x:list[src])
        {
            edges++;
            if(!visit[x])
            {
                dfs(x,visit,list,edges,nodes);
            }
        }
        
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>list[n];
        for(auto edge:connections)
        {
            list[edge[0]].push_back(edge[1]);
            list[edge[1]].push_back(edge[0]);
        }
        int extraEdges=0,components=0;
        vector<int>visit(n,false);
        for(int i=0;i<n;i++)
        {
            int edges=0,nodes=0;
            if(visit[i])continue;
            dfs(i,visit,list,edges,nodes);
            edges/=2;
            extraEdges+=edges-nodes+1;
            components++;
        }
        if(extraEdges>=components-1)
            return components-1;
        return -1;
    }
};