class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>rgraph(n);
        queue<int>que;
        vector<int>inorder(n);
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                rgraph[graph[i][j]].push_back(i);
                inorder[i]++;
            }

            if(graph[i].size()==0)
            {
                que.push(i);
            }
        }
        vector<int>res;
        while(!que.empty())
        {
            int curr=que.front();
            res.push_back(curr);
            que.pop();
            for(auto child:rgraph[curr])
            {
                inorder[child]--;
                if(inorder[child]==0)
                    que.push(child);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};