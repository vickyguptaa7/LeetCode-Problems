class Solution {
public:
    
    bool dfs(int src,vector<vector<int>>&list,vector<int>&visit,vector<int>&recurVisit)
    {
        visit[src]=true;
        recurVisit[src]=true;
        for(auto child:list[src])
        {
            if(visit[child])
            {
                if(recurVisit[child])
                    return true;
                continue;
            }
            if(dfs(child,list,visit,recurVisit))
                return true;
        }
        recurVisit[src]=false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>visit(graph.size(),0),recurVisit(graph.size(),0);
        for(int i=0;i<graph.size();i++)
        {
            if(visit[i])continue;
            dfs(i,graph,visit,recurVisit);
        }
        vector<int>safe;
        for(int i=0;i<graph.size();i++)
            if(!recurVisit[i])
                safe.push_back(i);
        return safe;
    }
};