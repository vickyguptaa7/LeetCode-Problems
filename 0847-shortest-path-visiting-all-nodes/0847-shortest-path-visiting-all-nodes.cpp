class Solution {
public:
    
    int shortestPathLength(vector<vector<int>>& graph) {
  int graphSize=graph.size();
        if(graphSize==1)return 0;
        
        // Contains node mask cost
        queue<pair<int,pair<int,int>>>que;
        
        set<pair<int,int>>visited;
        
        int allVisited=(1<<graphSize)-1;
        
        for(int i=0;i<graphSize;i++)
        {
            int mask=(1<<i);
            que.push({i,{mask,0}});
            visited.insert({i,mask});
        }
        
        while(!que.empty())
        {
            int mask=que.front().second.first;
            int cost=que.front().second.second;
            int parent=que.front().first;
            que.pop();
            for(auto child:graph[parent])
            {
                int Mask=(1<<child)|mask;
                int Cost=cost+1;
                if(Mask==allVisited)
                {
                    return Cost;
                }
                if(visited.count({child,Mask})==0)
                {
                    que.push({child,{Mask,Cost}});
                    visited.insert({child,Mask});
                }
            }
        }
        
        return -1;
    }
    
};