class Solution {
public:
    
    void dfs(int src,vector<int>list[],vector<int>&recurVisit,vector<int>&visit,int &node_cnt,
           int &longest_cycle)
    {
        visit[src]=true;
        recurVisit[src]=node_cnt++;
        for(auto child:list[src])
        {
            if(visit[child]||recurVisit[child])
            {
                if(recurVisit[child])
                {
                    longest_cycle=max(longest_cycle,node_cnt-recurVisit[child]);
                }
            }
            else
            {
                dfs(child,list,recurVisit,visit,node_cnt,longest_cycle);
            }
        }
        node_cnt--;
        recurVisit[src]=0;
    }
    
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>list[n];
        for(int i=0;i<n;i++)
        {
            if(edges[i]==-1)continue;
            list[i].push_back(edges[i]);
        }
        vector<int>visit(n,false);
        vector<int>recurVisit(n,false);
        int longest_cycle=-1;
        for(int i=0;i<n;i++)
        {
            if(visit[i])continue;
            int node_cnt=1;
            dfs(i,list,recurVisit,visit,node_cnt,longest_cycle);
        }
        return longest_cycle;
    }
};