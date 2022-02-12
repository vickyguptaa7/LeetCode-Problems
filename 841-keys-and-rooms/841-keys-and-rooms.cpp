class Solution {
public:
    void dfs(int src,vector<int>list[],vector<bool>&isVisited)
    {
        isVisited[src]=1;
        for(auto curr:list[src])
        {
            if(!isVisited[curr])
            {
                dfs(curr,list,isVisited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>list[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<rooms[i].size();j++)
            {
                list[i].push_back(rooms[i][j]);
            }
        }
        
        int component=0;
        vector<bool>isVisited(n,0);
        for(int i=0;i<n;i++)
        {
            if(!isVisited[i])
            {
                dfs(i,list,isVisited);
                component++;
            }
            if(component>=2)return false;
        }
        return true;
    }
};