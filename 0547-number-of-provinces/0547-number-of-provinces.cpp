class Solution {
public:
    
    void helperDfs(int src,vector<vector<int>>&isConnected,vector<bool>&visited)
    {
        visited[src]=true;
        for(int i=0;i<visited.size();i++)
        {
            if(!isConnected[src][i]||visited[i])continue;
                helperDfs(i,isConnected,visited);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>visited(n,0);
        int noOfProvince=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i])continue;
            noOfProvince++;
            helperDfs(i,isConnected,visited);
        }
        return noOfProvince;
    }
};