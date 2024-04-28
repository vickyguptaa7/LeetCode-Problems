class Solution {
public:
    
    pair<int,int> preCalc(int src,int par,vector<int>list[],vector<int>&node_cnt,vector<int>&node_dist)
    {
        int ndist=0,ncnt=1;
        for(auto child:list[src])
        {
            if(child==par)continue;
            auto val=preCalc(child,src,list,node_cnt,node_dist);
            ncnt+=val.first;
            ndist+=val.second+val.first;
        }
        node_cnt[src]=ncnt;
        node_dist[src]=ndist;
        return {ncnt,ndist};
    }
    
    void helper(int src,int par,int n,vector<int>list[],vector<int>&node_cnt,vector<int>&node_dist)
    {
        for(auto child:list[src])
        {
            if(child==par)continue;
            node_dist[child]=(n-node_cnt[child])-node_cnt[child]+node_dist[src];
            helper(child,src,n,list,node_cnt,node_dist);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>list[n];
        for(auto &edge:edges)
        {
            list[edge[0]].push_back(edge[1]);
            list[edge[1]].push_back(edge[0]);
        }
        vector<int>node_cnt(n,0),node_dist(n,0);
        preCalc(0,-1,list,node_cnt,node_dist);
        helper(0,-1,n,list,node_cnt,node_dist);
        return node_dist;
    }
};