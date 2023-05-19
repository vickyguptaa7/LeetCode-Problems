class Solution {
public:
    
    int dfs(int src,int par,int col,vector<vector<int>>&graph,vector<int>&color)
    {
        color[src]=col;
        for(auto child:graph[src])
        {
            if(color[child]==-1)
            {
                if(!dfs(child,src,col==1?2:1,graph,color))
                    return false;
            }
            else 
            {
                if(color[child]==color[src])
                    return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
            if(color[i]==-1&&!dfs(i,-1,1,graph,color))
                return false;
        return true;
    }
    
};