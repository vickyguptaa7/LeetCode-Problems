class Solution {
public:
    
    pair<int,int>dfs(int src,int par,vector<int>&visited,vector<int>list[])
    {
        visited[src]++;
        int nodeCnt=1,edgeCnt=list[src].size();
        for(auto child:list[src])
        {
            if(visited[child])
            {
                continue;
            }
            auto curr=dfs(child,src,visited,list);
            edgeCnt+=curr.second;
            nodeCnt+=curr.first;
        }
        return {nodeCnt,edgeCnt};
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>list[n];
        for(auto edge:edges)
        {
            list[edge[0]].push_back(edge[1]);
            list[edge[1]].push_back(edge[0]);
        }
        vector<int>visited(n,false);
        int cntr=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i])continue;
            auto res=dfs(i,-1,visited,list);
            int edgeCnt=res.second;
            int nodeCnt=res.first;
            if(edgeCnt==nodeCnt*(nodeCnt-1))cntr++;
        }
        return cntr;
    }
};