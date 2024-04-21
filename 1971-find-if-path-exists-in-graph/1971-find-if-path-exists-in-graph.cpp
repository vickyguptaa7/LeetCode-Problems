class Solution {
public:
    
    bool helper(int src,vector<int>&visit,int des,vector<int>list[])
    {
        if(src==des)
            return true;
        visit[src]=true;
        for(auto child:list[src])
        {
            if(visit[child])continue;
            if(helper(child,visit,des,list))
                return true;
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>list[n];
        for(auto edge:edges)
        {
            list[edge[0]].push_back(edge[1]);
            list[edge[1]].push_back(edge[0]);
        }
        vector<int>visit(n,0);
        return helper(source,visit,destination,list);
    }
};