class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,int>>list[n];
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                list[i].push_back({abs(points[i][0]-points[j][0])
                    +abs(points[i][1]-points[j][1]),j});
                list[j].push_back({abs(points[i][0]-points[j][0])
                    +abs(points[i][1]-points[j][1]),i});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pque;
        pque.push({0,0});
        vector<bool>visit(n,false);
        int totalCost=0;
        while(!pque.empty())
        {
            int src=pque.top().second;
            int cost=pque.top().first;
            pque.pop();
            if(visit[src]==true)continue;
            totalCost+=cost;
            visit[src]=true;
            for(auto curr:list[src])
            {
                if(visit[curr.second]==false)
                {
                    pque.push(curr);
                }
            }
        }
        return totalCost;
    }
};