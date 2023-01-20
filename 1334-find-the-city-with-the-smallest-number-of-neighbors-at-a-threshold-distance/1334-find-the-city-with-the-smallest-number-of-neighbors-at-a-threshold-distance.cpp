class Solution {
public:
    
    vector<int>dijkstra_algo(int src,vector<pair<int,int>>list[],int n)
    {
        vector<int>distance(n,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>pque;
        pque.push({0,src});
        distance[src]=0;
        while(!pque.empty())
        {
            auto curr=pque.top();
            pque.pop();
            for(auto x:list[curr.second])
            {
                if(distance[x.first]>curr.first+x.second)
                {
                    distance[x.first]=curr.first+x.second;
                    pque.push({distance[x.first],x.first});
                }
            }
        }
        return distance;
        
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>>list[n];
        for(auto x:edges)
        {
            list[x[0]].push_back({x[1],x[2]});
            list[x[1]].push_back({x[0],x[2]});
        }
        vector<vector<int>>distanceToAllNodes;
        int mnThreshold=1e9;
        for(int i=0;i<n;i++)
        {
            vector<int>dist=dijkstra_algo(i,list,n);
            distanceToAllNodes.push_back(dist);
            int cntr=0;
            for(auto x:dist)
            {
                if(x<=distanceThreshold)cntr++;
            }
            mnThreshold=min(cntr,mnThreshold);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int cntr=0;
            for(auto x:distanceToAllNodes[i])
            {
                if(x<=distanceThreshold)cntr++;
            }
            if(mnThreshold==cntr)
                ans=i;
        }
        return ans;
    }
};