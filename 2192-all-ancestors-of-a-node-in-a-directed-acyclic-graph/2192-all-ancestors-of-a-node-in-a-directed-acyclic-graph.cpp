class Solution {
public:
    
    void unionSet(unordered_set<int>&a,unordered_set<int>&b)
    {
        for(auto &x:a)
        {
            if(!b.count(x))
                b.insert(x);
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>in(n);
        vector<int>list[n];
        for(auto edge:edges)
        {
            in[edge[1]]++;
            list[edge[0]].push_back(edge[1]);
        }
        unordered_set<int>par[n];
        queue<int>que;
        for(int i=0;i<n;i++)
        {
            if(!in[i])
                que.push(i);
        }
        while(!que.empty())
        {
            int node=que.front();
            que.pop();
            for(auto child:list[node])
            {
                in[child]--;
                par[child].insert(node);
                unionSet(par[node],par[child]);
                if(!in[child])
                {
                    que.push(child);
                }
            }
        }
        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++)
        {
            for(auto x:par[i])
            {
                ans[i].push_back(x);
            }
            sort(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};