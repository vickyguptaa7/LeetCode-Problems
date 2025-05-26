class Solution {
public:

    vector<int> dfs(int src,int par,vector<int>list[],map<int,vector<int>>&dp,string& colors)
    {
        if(dp.count(src))
            return dp[src];
        vector<int>freq(26,0);
        for(int i=0;i<list[src].size();i++)
        {
            if(par==list[src][i])continue;
            vector<int>temp=dfs(list[src][i],src,list,dp,colors);
            for(int i=0;i<26;i++)freq[i]=max(freq[i],temp[i]);
        }
        freq[colors[src]-'a']++;
        return dp[src]=freq;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<int>list[n];
        vector<int>inorder(n,0);
        for(auto edge:edges)
        {
            inorder[edge[1]]++;
            list[edge[0]].push_back(edge[1]);
        }
        vector<int>topo;
        queue<int>que;
        for(int i=0;i<n;i++)
        {
            if(inorder[i]==0)
                que.push(i);
        }
        while(!que.empty())
        {
            int curr=que.front();
            que.pop();
            topo.push_back(curr);
            for(int i=0;i<list[curr].size();i++)
            {
                inorder[list[curr][i]]--;
                if(inorder[list[curr][i]]==0)
                {
                    que.push(list[curr][i]);
                }
            }
        }
        if(topo.size()!=n)
            return -1;
        
        map<int,vector<int>>dp;
        int res=0;

        for(int i=0;i<topo.size();i++)
        {
            if(dp.count(topo[i]))continue;
            dfs(topo[i],-1,list,dp,colors);
        }
        for(int i=0;i<topo.size();i++)
        {
            cout<<topo[i]<<" :-> ";
            for(auto x:dp[topo[i]])
            {
                cout<<x<<" ";
                res=max(res,x);
            }
            cout<<"\n";
        }
        return res;
    }
};