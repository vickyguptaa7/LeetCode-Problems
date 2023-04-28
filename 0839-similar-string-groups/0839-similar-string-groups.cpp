class Solution
{
    public:
    
        void dfs(int src,vector<int>list[],vector<int>&visited)
        {
            visited[src]=true;
            for(auto &child:list[src])
            {
                if(!visited[child])
                {
                    dfs(child,list,visited);
                }
            }
        }
        
        int numSimilarGroups(vector<string> &strs)
        {
            int n = strs.size();
            vector<int> list[n];
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    int diff = 0;
                    for (int k = 0; k < strs[i].size(); k++)
                    {
                        if (strs[i][k] != strs[j][k]) 
                        {
                            diff++; 
                            if(diff>2)break;
                        }
                    }
                    if(diff<=2)
                    {
                        list[i].push_back(j);
                        list[j].push_back(i);
                    }
                }
            }
            vector<int>visited(n);
            int comp=0;
            for(int i=0;i<n;i++)
            {
                if(!visited[i])
                {
                    dfs(i,list,visited);
                    comp++;
                }
            }
            return comp;
        }
};