class Solution {
public:
    
    void dfs(int src,vector<int>list[],vector<bool>&visited,int &count)
    {
        count++;
        visited[src]=true;
        for(auto x:list[src])
        {
            if(visited[x]==false)
            {
                dfs(x,list,visited,count);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>list[n];
        for(auto x:edges)
        {
            list[x[0]].push_back(x[1]);
            list[x[1]].push_back(x[0]);
        }
        
        vector<bool>visited(n,false);
        vector<int>grpCount;
        
        for(int i=0;i<n;i++)
        {
            int count=0;
            if(visited[i]==false)
            dfs(i,list,visited,count);
            
            if(count!=0)
            grpCount.push_back(count);
        }
        
        long long res=0;
        long long sum=accumulate(grpCount.begin(),grpCount.end(),0ll);
        for(int i=0;i<grpCount.size();i++)
        {
            sum-=grpCount[i];
            res+=grpCount[i]*sum;
        }
        return res;
    }
};