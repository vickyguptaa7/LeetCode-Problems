class Solution {
public:
    
    vector<vector<long long>>allSourceShortestPath(vector<vector<long long>>&adj)
    {
        int n=adj.size(),m=adj[0].size();
        vector<vector<long long>>nadj=adj;
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(j==i)
                        nadj[i][j]=0;
                    else 
                        nadj[i][j]=min(nadj[i][j],nadj[i][k]+nadj[k][j]);
                }
            }
        }
        return nadj;
    }
    
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>adj(26,vector<long long>(26,1e9));
        for(int i=0;i<original.size();i++)
        {
            adj[original[i]-'a'][changed[i]-'a']=min(adj[original[i]-'a'][changed[i]-'a'],cost[i]+0ll);
        }
        vector<vector<long long>>nadj=allSourceShortestPath(adj);
        long long ncost=0;
        for(int i=0;i<source.size();i++)
        {
            if(nadj[source[i]-'a'][target[i]-'a']>=1e9)
                return -1;
            ncost+=nadj[source[i]-'a'][target[i]-'a'];
        }
        return ncost;
    }
};