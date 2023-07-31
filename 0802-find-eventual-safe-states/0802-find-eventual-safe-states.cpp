class Solution {
    
    bool dfsCycleDetect(int src,vector<int>&visited
                        ,vector<int>&recurVisited,
                        vector<int>&isCycle,vector<vector<int>>&list)
    {
        visited[src]=true;
        recurVisited[src]=true;
        for(auto child:list[src])
        {
            if(visited[child])
            {
                if(recurVisited[child]||isCycle[child])
                {
                    recurVisited[src]=false;
                    return isCycle[src]=1;
                }
                continue;
            }
            if(dfsCycleDetect(child,visited,recurVisited,isCycle,list))
            {
                recurVisited[src]=false;
                return isCycle[src]=1;
            }
        }
        recurVisited[src]=false;
        return false;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>isCycle(n,0);
        vector<int>visited(n,0);
        vector<int>recurVisit(n,0);
        for(int i=0;i<n;i++)
        {
            if(visited[i])
                continue;
            dfsCycleDetect(i,visited,recurVisit,isCycle,graph);
        }
        vector<int>result;
        for(int i=0;i<n;i++)
        {
            if(isCycle[i])continue;
            result.push_back(i);
        }
        return result;
    }
};