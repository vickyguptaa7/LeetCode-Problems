class Solution {
public:
    
    void helper(int src,vector<vector<int>>&graph,vector<int>path,
               vector<vector<int>>&allPaths)
    {
        if(src+1==graph.size())
        {
            allPaths.push_back(path);
            return;
        }
        for(auto x:graph[src])
        {
            path.push_back(x);
            helper(x,graph,path,allPaths);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>allPaths;
        vector<int>path={0};
        helper(0,graph,path,allPaths);
        return allPaths;
    }
};