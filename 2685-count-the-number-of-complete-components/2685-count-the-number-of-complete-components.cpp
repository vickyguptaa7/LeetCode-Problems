class Solution {
public:

    void helper(int src,vector<int>list[],vector<int>&visited,int mark)
    {
        visited[src]=mark;
        for(int i=0;i<list[src].size();i++)
        {
            if(visited[list[src][i]])continue;
            helper(list[src][i],list,visited,mark);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>visited(n,0);
        vector<int>list[n];
        for(auto edge:edges)
        {
            list[edge[0]].push_back(edge[1]);
            list[edge[1]].push_back(edge[0]);
        }
        int count=0,mark=1;
        for(int i=0;i<n;i++)
        {
            if(visited[i])continue;
            helper(i,list,visited,mark);
            int same=0,isComplete=true;
            for(int j=0;j<n;j++)
            {
                same+=(mark==visited[j]);
            }
            for(int j=0;j<n;j++)
            {
                if(mark==visited[j])
                {
                    if(same-1!=list[j].size())
                    {
                        isComplete=false;
                    }
                }
            }
            mark++;
            count+=isComplete;
        }
        return count;
    }
};