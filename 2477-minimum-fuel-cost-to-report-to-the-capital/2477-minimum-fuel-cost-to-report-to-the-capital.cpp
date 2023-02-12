class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size()+1;
        vector<int>list[n];
        for(auto x:roads)
        {
            list[x[0]].push_back(x[1]);
            list[x[1]].push_back(x[0]);
        }
        long long ans=0;
        helperDfs(0,-1,list,seats,ans);
        return ans;
    }
    
    long long helperDfs(int src,int par,vector<int>list[],int &seats,long long &ans)
    {
        int nodeCnt=0;
        for(auto child:list[src])
        {
            if(child!=par)
            {
                long long curr=1+helperDfs(child,src,list,seats,ans);
                ans+=ceil(curr/(double)seats);
                nodeCnt+=curr;
            }
        }
        return nodeCnt;
    }
};