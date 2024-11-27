class Solution {
public:
    
    int bfs(int src,int dest,int n,vector<int>list[])
    {
        queue<int>que;
        vector<int>dist(n,n+1);
        que.push(src);
        dist[src]=0;
        while(!que.empty())
        {
            int curr=que.front();
            que.pop();
            for(auto child:list[curr])
            {
                if(dist[child]>1+dist[curr])
                {
                    dist[child]=1+dist[curr];
                    que.push(child);
                }
            }
        }
        return dist.back();
    }
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>list[n];
        for(int i=1;i<n;i++)
        {
            list[i-1].push_back(i);
        }
        vector<int>res;
        for(int i=0;i<queries.size();i++)
        {
            list[queries[i][0]].push_back(queries[i][1]);
            res.push_back(bfs(0,n-1,n,list));
        }
        return res;
    }
};