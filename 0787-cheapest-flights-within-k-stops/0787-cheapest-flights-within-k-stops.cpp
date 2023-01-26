class Solution {
public:
    typedef pair<int,pair<int,int>> ppi;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>>list[n];
        
        for(int i=0;i<flights.size();i++)
        {
            list[flights[i][0]].push_back
                ({flights[i][1],flights[i][2]});
        }
        
        priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
        pq.push({0,{src,0}});
        
        vector<int>stop(n,1e9);
        
        while(pq.size())
        {
            int node=pq.top().second.first;
            int weight=pq.top().first;
            int radial_dist=pq.top().second.second;
            pq.pop();
            if(radial_dist>stop[node]||radial_dist>k+1)
            {
                continue;
            }
            stop[node]=radial_dist;
            if(dst==node)
            {
                return weight;
            }
            for(auto x:list[node])
            {
                pq.push({weight+x.second,{x.first,radial_dist+1}});
            }
        }
        return -1;
    }
};