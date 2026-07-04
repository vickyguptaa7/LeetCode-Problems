class Solution {
public:

    void helper(int src,vector<pair<int,int>>list[],vector<int>&visited,int &minSc)
    {   
        visited[src]=true;
        for(auto [node,cost]:list[src])
        {
            minSc=min(minSc,cost);
            if(visited[node])
                continue;
            helper(node,list,visited,minSc);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> list[n+1];
        for(auto road:roads)
        {
            list[road[0]].push_back({road[1],road[2]});
            list[road[1]].push_back({road[0],road[2]});
        }
        int cost=1e9;
        vector<int>visited(n+1,false);
        helper(1,list,visited,cost);
        return cost;
    }
};