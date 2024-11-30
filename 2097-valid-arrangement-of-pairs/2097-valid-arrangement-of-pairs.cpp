class Solution {
public:
    
    void dfs(int startNode,unordered_map<int,stack<int>>&graph,vector<pair<int,int>>&ans)
    {
        auto& st=graph[startNode];
        while(!st.empty())
        {
            int newStartNode=st.top();
            st.pop();
            dfs(newStartNode,graph,ans);
            ans.push_back({startNode,newStartNode});
        }
    }
    
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n=pairs.size();
        unordered_map<int,stack<int>>graph;
        unordered_map<int,int>inorder,outorder;
        for(int i=0;i<pairs.size();i++)
        {
            int u=pairs[i][0],v=pairs[i][1];
            graph[u].push(v);
            inorder[v]++;
            outorder[u]++;
        }
        int startNode=graph.begin()->first;
        for(auto g:graph)
        {
            if(outorder[g.first]-inorder[g.first]==1)
            {
                startNode=g.first;
                break;
            }
        }
        cout<<startNode<<"\n";
        vector<pair<int,int>>ans;
        dfs(startNode,graph,ans);
        reverse(ans.begin(),ans.end());
        vector<vector<int>>res;
        for(int i=0;i<ans.size();i++)
        {
            res.push_back({ans[i].first,ans[i].second});
        }
        return res;
    }
};