class Solution {
public:
    
int shortestPath(int src, int dst, int n, vector<int> list[])
{
    queue<int> que;
    vector<int> visit(n + 1, 0);
    visit[src] = 1;
    que.push(src);
    int time = 0;
    while (!que.empty())
    {
        int size = que.size();
        while (size--)
        {
            int curr = que.front();
            que.pop();
            if (dst == curr)
                return time;
            for (auto child : list[curr])
            {
                // skip edge src-dst
                if ((curr == src && child == dst) || (curr == dst && child == src))
                    continue;
                if (visit[child])
                    continue;
                que.push(child);
                visit[child] = true;
            }
        }
        time++;
    }
    return 1e9;
}

    
    int findShortestCycle(int n, vector<vector<int>>& edges) {
    vector<int> list[n + 1];
    for (int i = 0; i < edges.size(); i++)
    {
        int u=edges[i][0], v=edges[i][1];
        list[u].push_back(v);
        list[v].push_back(u);
    }
    int cycle = 1e9;
    for (int i = 0; i < edges.size(); i++)
    {
        int src = edges[i][0], dst = edges[i][1];
        // avoid edge src - dst
        // find shortest dist between src to dst without the edge src - dst
        cycle = min(cycle, shortestPath(src, dst, n, list) + 1);
    }
    return cycle==1e9?-1:cycle;
}
};