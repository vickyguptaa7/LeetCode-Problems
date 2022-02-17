class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int result=0,n=cost.size();
        if(n==1)return cost[0];
        sort(cost.begin(),cost.end());
        int i;
        for(i=n-1;i>=1;i-=2)
        {
            result+=cost[i]+cost[i-1];
            i--;
        }
        if(i==0)result+=cost[i];
        return result;
    }
};