class Solution {
public:
    
    void dfs(int src,int par,vector<pair<int,int>>list[],int &edgeReverse)
    {
        for(auto [child,isCorrect]:list[src])
        {
            if(par==child)continue;
            edgeReverse+=isCorrect;
            dfs(child,src,list,edgeReverse);
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int,int>>list[n];
        for(int i=0;i<connections.size();i++)
        {
            list[connections[i][0]].push_back({connections[i][1],1});
            list[connections[i][1]].push_back({connections[i][0],0});
        }
        int edgeReverse=0;
        dfs(0,-1,list,edgeReverse);
        return edgeReverse;
    }
};