class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>in(graph.size(),0);
        vector<int>safe;
        vector<int>revGraph[graph.size()];
        for(int i=0;i<graph.size();i++)
        {
            for(auto x:graph[i])
            {
                revGraph[x].push_back(i);
            }
        }
        for(int i=0;i<graph.size();i++)
        {
            for(auto x:revGraph[i])
            {
                in[x]++;
            }
        }
        queue<int>que;
        for(int i=0;i<in.size();i++)
        {
            if(!in[i])
            {
                safe.push_back(i);
                que.push(i);
            }
        }
        while(!que.empty())
        {
            int src=que.front();
            que.pop();
            for(auto child:revGraph[src])
            {
                in[child]--;
                if(!in[child])
                {
                    que.push(child);
                    safe.push_back(child);
                }
            }
        }
        sort(safe.begin(),safe.end());
        return safe;
    }
};