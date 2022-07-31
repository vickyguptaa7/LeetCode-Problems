class Solution {
public:
    
    void bfs(int src,vector<int>list[],vector<int>&dist)
    {
        dist[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pque;
        pque.push({0,src});
        while(!pque.empty())
        {
            auto curr=pque.top();
            pque.pop();
                
            for(auto x:list[curr.second])
            {
                if(dist[x]>curr.first+1)
                {
                    dist[x]=curr.first+1;
                    pque.push({dist[x],x});
                }
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>list[n];
        for(int i=0;i<n;i++)
        {
            if(edges[i]==-1)continue;
            list[i].push_back(edges[i]);
        }
        vector<int>dist1(n,1e9),dist2(n,1e9);
        bfs(node1,list,dist1);
        bfs(node2,list,dist2);
        
        vector<vector<int>>combi;
        for(int i=0;i<n;i++)
        {
            combi.push_back({dist1[i],dist2[i],i});
        }
        int ans=-1,dist=1e9;
        for(int i=0;i<n;i++)
        {
            if(combi[i][0]!=1e9&&combi[i][1]!=1e9&&max(combi[i][0],combi[i][1])<dist)
            {
                dist=max(combi[i][0],combi[i][1]);
                ans=combi[i][2];
            }
        }
        return ans;
    }
};