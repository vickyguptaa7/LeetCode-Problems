class Solution {
public:

    int dfs(int src,int par,map<int,set<int>>&list,map<int,int>&visit)
    {
        if(visit[src])
            return 0;
        int count=1;
        visit[src]=1;
        for(auto child:list[src])
        {
            if(child==par||visit[child])continue;
            count+=dfs(child,src,list,visit);
        }
        return count;
    }

    int countServers(vector<vector<int>>& grid) {
        map<int,set<int>>list;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!grid[i][j])continue;
                int u=i*m+j;
                for(int k=j+1;k<m;k++)
                {
                    if(!grid[i][k])continue;
                    int v=i*m+k;
                    list[u].insert(v);
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!grid[j][i])continue;
                int u=j*m+i;
                for(int k=j+1;k<n;k++)
                {
                    if(!grid[k][i])continue;
                    int v=k*m+i;
                    list[u].insert(v);
                }
            }
        }
        int count=0;
        map<int,int>visit;
        for(auto x:list)
        {
            count+=dfs(x.first,-1,list,visit);
        }
        return count;
    }
};