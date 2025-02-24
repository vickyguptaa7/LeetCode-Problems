class Solution {
public:

    bool helper1(int src,int par,int time,vector<vector<int>>&list,vector<int>&times)
    {
        if(src==0)
        {
            times[src]=time;
            return true;
        }
        for(auto child:list[src])
        {
            if(child==par)continue;
            if(helper1(child,src,time+1,list,times))
            {
                times[src]=time;
                return true;
            }
        }
        return false;
    }

    int helper2(int src,int par,int time,vector<vector<int>>&list,vector<int>&times,vector<int>&amount)
    {
        int cost=-1e9;
        for(auto child:list[src])
        {
            if(child==par)continue;
            cost=max(cost,helper2(child,src,time+1,list,times,amount));
        }
        cost=cost==-1e9?0:cost;
        if(time<times[src]||times[src]==-1)
        {
            cost+=amount[src];
        }
        else if(time==times[src])
        {
            cost+=amount[src]/2;
        }
        return cost;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size()+1;
        vector<vector<int>>list(n);
        for(auto edge:edges)
        {
            list[edge[0]].push_back(edge[1]);
            list[edge[1]].push_back(edge[0]);   
        }
        vector<int>time(n,-1);
        helper1(bob,-1,0,list,time);
        return helper2(0,-1,0,list,time,amount);
    }
};