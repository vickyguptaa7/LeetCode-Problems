class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>>list[n];
        for(auto edge:flights)
        {
            list[edge[0]].push_back({edge[1],edge[2]});
        }
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>
            pque;
        pque.push({0,0,src});
        vector<int>stops(n,1e9);
        stops[src]=0;
        while(!pque.empty())
        {
            int cost=pque.top()[0];
            int stop=pque.top()[1];
            int curr=pque.top()[2];
            
            pque.pop();
            if(curr==dst)
                return cost;
            
            if(stop>k||stops[curr]<stop)
                continue;
            stops[curr]=stop;
            for(auto child:list[curr])
            {
                pque.push({cost+child.second,stop+1,child.first});
            }
        }
        return -1;
        
    }
};