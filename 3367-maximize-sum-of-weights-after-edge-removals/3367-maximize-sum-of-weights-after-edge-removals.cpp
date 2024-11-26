bool comp(pair<long long,long long>&a,pair<long long,long long>&b)
{
    return a.first-a.second<b.first-b.second;
}

class Solution {
    long long dp[100001][2];
public:
    
    long long helper(int src,int par,int isParent,vector<pair<int,int>>list[],int k)
    {
        if(dp[src][isParent]!=-1)
            return dp[src][isParent];
        
        long long sum=0;
        int remove=max(isParent?(int)list[src].size()-k:(int)list[src].size()-k-1,0);
        vector<pair<long long,long long>>t;
        for(auto child:list[src])
        {
            if(child.first==par)
                continue;
            t.push_back({child.second+helper(child.first,src,1,list,k),helper(child.first,src,0,list,k)});
        }
        sort(t.begin(),t.end(),comp);
        for(int i=0;i<t.size();i++)
        {
            if(i<remove)
            {
                sum+=t[i].second;
            }
            else
            {
                sum+=max(t[i].first,t[i].second);
            }
        }
        
        return dp[src][isParent]=sum;
    }
    
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        int n=edges.size();
        memset(dp,-1,sizeof(dp));
        vector<pair<int,int>>list[n+1];
        for(auto edge:edges)
        {
            list[edge[0]].push_back({edge[1],edge[2]});
            list[edge[1]].push_back({edge[0],edge[2]});
        }
        list[0].push_back({-1,0});
        return helper(0,-1,0,list,k);
    }
};