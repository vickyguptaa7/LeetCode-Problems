class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        color[0]=0;
        queue<int>que;
        que.push(0);
        while(true)
        {
        
            while(!que.empty())
            {
             int parent=que.front();
             que.pop();
             for(auto curr:graph[parent])
             {
                if(color[curr]==-1)
                {
                    color[curr]=(color[parent]==0)?1:0;
                    que.push(curr);
                }
                else if(color[curr]==color[parent])
                {
                    return false;
                }
              }
             }
            bool istrue=true;
            for(int i=0;i<n;i++)
            {
                if(color[i]==-1)
                {
                    color[i]=0;
                    que.push(i);
                    istrue=false;
                    break;
                }
            }
            if(istrue)break;
        }

        return true;
    }
};