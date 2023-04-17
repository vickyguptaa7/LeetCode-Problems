class Graph {
public:
    vector<pair<int,int>>*list;
    int n;
    Graph(int n, vector<vector<int>>& edges) {
        list=new vector<pair<int,int>>[n];
        this->n=n;
        for(auto edge:edges)
        {
            list[edge[0]].push_back({edge[1],edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        list[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pque;
        pque.push({0,node1});
        vector<int>dist(n,1e9);
        dist[node1]=0;
        while(!pque.empty())
        {
            auto curr=pque.top().second;
            auto cost=pque.top().first;
            pque.pop();
            if(curr==node2)
            {
                return cost;
            }
            for(auto [child,ccost]:list[curr])
            {
                if(dist[child]>cost+ccost)
                {
                    dist[child]=cost+ccost;
                    pque.push({dist[child],child});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */