class Solution {
public:
    
    pair<int,int> helper(int src,int par,vector<int>list[],vector<int>&values,int k)
    {
        pair<int,int>curr={0,0};
        for(auto child:list[src])
        {
            if(child==par)continue;
            pair<int,int>info=helper(child,src,list,values,k);
            curr.first+=info.first;
            curr.second+=info.second;
        }
        curr.first+=values[src];
        return {curr.first%k,(curr.first%k==0?1+curr.second:curr.second)};
    }
    
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int>list[n];
        for(auto edge:edges)
        {
            list[edge[0]].push_back(edge[1]);
            list[edge[1]].push_back(edge[0]);
        }
        return helper(0,-1,list,values,k).second;
    }
};