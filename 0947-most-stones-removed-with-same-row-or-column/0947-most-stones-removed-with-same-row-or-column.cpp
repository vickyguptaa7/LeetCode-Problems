class Solution {
public:
    void dfs(int src,vector<int>list[],vector<int>&visited,int &cycle)
    {
        cycle++;
        visited[src]=true;
        for(auto x:list[src])
        {
            if(!visited[x])
            {
                dfs(x,list,visited,cycle);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int>list[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1])
                {
                    list[i].push_back(j);
                }
            }
        }
        vector<int>visited(n,false);
        int maxRemove=0;
        for(int i=0;i<n;i++)
        {
            int cycle=0;
            if(!visited[i])
            {
                dfs(i,list,visited,cycle);
                maxRemove+=cycle-1;
            }
        }
        return maxRemove;
    }
};