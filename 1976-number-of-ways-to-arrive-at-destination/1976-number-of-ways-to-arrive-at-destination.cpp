class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>list[n];
        long long mod=1e9+7;
        for(auto road:roads)
        {
            list[road[0]].push_back({road[1],road[2]});
            list[road[1]].push_back({road[0],road[2]});
        }
        vector<long long>distance(n,1e15),ways(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,
        greater<pair<long long,int>>>pque;
        pque.push({0,0});
        ways[0]=1;
        distance[0]=0;
        while(!pque.empty())
        {
            auto parent=pque.top();
            pque.pop();
            for(auto child:list[parent.second])
            {
                if(parent.first+child.second==distance[child.first])
                {
                    ways[child.first]=(ways[child.first]+ways[parent.second])%
                        mod;
                }
                else if(parent.first+child.second<distance[child.first])
                {
                    distance[child.first]=parent.first+child.second;
                    pque.push({distance[child.first],child.first});
                    ways[child.first]=ways[parent.second];
                }
            }
        }
        return ways[n-1];
        
    }
};