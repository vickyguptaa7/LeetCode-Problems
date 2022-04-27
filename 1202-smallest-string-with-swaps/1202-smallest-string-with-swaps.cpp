class Solution {
public:
    
    void dfs(int src,vector<int>list[],vector<bool>&visit,vector<int>&cCmpt)
    {
        visit[src]=true;
        cCmpt.push_back(src);
        for(auto x:list[src])
        {
            if(visit[x]==false)
            {
                dfs(x,list,visit,cCmpt);
            }
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        vector<int>list[n];
        for(int i=0;i<pairs.size();i++)
        {
            list[pairs[i][0]].push_back(pairs[i][1]);
            list[pairs[i][1]].push_back(pairs[i][0]);
        }
        vector<bool>visit(n,false);
        for(int i=0;i<n;i++)
        {
            vector<int>cCmpt;
            if(visit[i]==false)
            {
                dfs(i,list,visit,cCmpt);
            }
            if(!cCmpt.empty())
            {
                string tmp;
                for(int i=0;i<cCmpt.size();i++)tmp+=s[cCmpt[i]];
                sort(tmp.begin(),tmp.end());
                sort(cCmpt.begin(),cCmpt.end());
                for(int i=0;i<cCmpt.size();i++)s[cCmpt[i]]=tmp[i];
            }
        }
        return s;
    }
};