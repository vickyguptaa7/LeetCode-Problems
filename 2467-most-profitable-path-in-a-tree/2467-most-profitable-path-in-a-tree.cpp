class Solution {
public:
    int pathToRoot(int src,int time,vector<int>list[],map<int,int>&path,vector<int>&visited)
    {
        visited[src]=true;
        if(src==0)
        {
            path[src]=time;
            return true;
        }
        for(auto x:list[src])
        {
            if(!visited[x]&&pathToRoot(x,time+1,list,path,visited))
            {
                path[src]=time;
                return true;
            }
        }
        return false;
    }
    int maxProfitDfs(int src,int time,vector<int>list[],vector<int>&visited,vector<int>&amount,
                     map<int,int>&path)
    {
        visited[src]=true;
        int profit=-1e9;
        for(auto x:list[src])
        {
            if(!visited[x])
            {
                if(path.count(x)&&path[x]==time)
                {
                     profit=max(profit,maxProfitDfs(x,time+1,list,visited,amount,path)
                                +amount[x]/2);
                }
                else if(path.count(x)&&path[x]<time)
                {
                     profit=max(profit,maxProfitDfs(x,time+1,list,visited,amount,path));
                }
                else 
                {
                    profit=max(profit,maxProfitDfs(x,time+1,list,visited,amount,path)
                               +amount[x]);
                }
            }
                
        }
        return profit==-1e9?0:profit;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size()+1;
        vector<int>list[n];
        for(int i=0;i<n-1;i++)
        {
            list[edges[i][0]].push_back(edges[i][1]);
            list[edges[i][1]].push_back(edges[i][0]);
        }
        map<int,int>bobPath;
        vector<int>visited(n,false);
        pathToRoot(bob,0,list,bobPath,visited);
        for(int i=0;i<n;i++)visited[i]=false;
        int maxProfit=maxProfitDfs(0,1,list,visited,amount,bobPath)+amount[0];
        return maxProfit;
    }
};