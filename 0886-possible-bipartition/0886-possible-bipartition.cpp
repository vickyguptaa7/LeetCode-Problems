class Solution {
public:
    
    bool bipartite(int src,vector<int>list[],vector<int>&color,vector<int>&visit)
    {
        visit[src]=true;
        int clr=(color[src]==1)?2:1;
        for(auto x:list[src])
        {
            if(!visit[x])
            {
                color[x]=clr;
                if(!bipartite(x,list,color,visit))
                    return false;
            }
            else if(color[x]==color[src])
            {
                return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>list[n+1];
        for(int i=0;i<dislikes.size();i++)
        {
            list[dislikes[i][0]].push_back(dislikes[i][1]);
            list[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int>color(n+1,0),visit(n+1,false);
        for(int i=1;i<=n;i++)
        {
            if(visit[i])continue;
            color[i]=1;
            if(!bipartite(i,list,color,visit))
                return false;
        }
        return true;
    }
};