class Solution {
public:
    
    double helper(int src,int end,vector<pair<int,double>>list[],vector<int>&visit)
    {
        priority_queue<pair<double,int>>pque;
        pque.push({1,src});
        while(!pque.empty())
        {
            int node=pque.top().second;
            double cost=pque.top().first;
            visit[node]=true;
            pque.pop();
            if(node==end)
                return cost;
            for(auto curr:list[node])
            {
                if(visit[curr.first])continue;
                pque.push({curr.second*cost,curr.first});
            }
        }
        return 0;
    }
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>>list[n];
        for(int i=0;i<edges.size();i++)
        {
            list[edges[i][0]].push_back({edges[i][1],succProb[i]});
            list[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<int>visit(n,0);
        return helper(start_node,end_node,list,visit);
    }
};