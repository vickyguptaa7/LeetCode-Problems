class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>list[n+1];
        for(int i=0;i<trust.size();i++)
        {
            list[trust[i][0]].push_back(trust[i][1]);
        }
        vector<int>indegree(n+1,0),outdegree(n+1,0);
        for(int i=0;i<=n;i++)
        {
            for(auto x:list[i])
            {
                indegree[x]++;
            }
            outdegree[i]=list[i].size();
        }
        for(int i=1;i<=n;i++)
        {
            if(indegree[i]==n-1)
            {
                if(outdegree[i]==0)return i;
            }
        }
        return -1;
    }
};