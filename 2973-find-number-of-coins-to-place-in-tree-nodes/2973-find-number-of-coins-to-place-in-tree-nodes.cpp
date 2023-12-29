class Solution {
public:
    
    vector<long long> helper(int src,int par,vector<int>list[],vector<int>&cost,vector<long long>&res)
    {
        vector<long long>dcosts={cost[src]};
        for(auto child:list[src])
        {
            if(child==par)continue;
            vector<long long> curr=helper(child,src,list,cost,res);
            for(auto e:curr)dcosts.push_back(e);
        }
        sort(dcosts.begin(),dcosts.end());
        int sz=dcosts.size();
        if(dcosts.size()<3)
        {
            res[src]=1;
            return dcosts;
        }
        else
        {
            res[src]=max({dcosts[sz-1]*dcosts[sz-2]*dcosts[sz-3],dcosts[sz-1]*dcosts[1]*dcosts[0],0ll});
        }
        if(sz<=5)
            return dcosts;
        return {dcosts[0],dcosts[1],dcosts[sz-3],dcosts[sz-2],dcosts[sz-1]};
    }
    
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n=edges.size()+1;
        vector<int>list[n+1];
        for(auto edge:edges)
        {
            list[edge[0]].push_back(edge[1]);
            list[edge[1]].push_back(edge[0]);
        }
        vector<long long>res(n,0);
        helper(0,-1,list,cost,res);
        return res;
    }
};