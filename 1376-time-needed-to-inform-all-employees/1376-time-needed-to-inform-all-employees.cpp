class Solution {
public:
    
    int helper(int src,vector<int>list[],vector<int>&informTime)
    {
        int time=0;
        for(auto child:list[src])
        {
            time=max(time,helper(child,list,informTime));
        }
        return time+informTime[src];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int>list[n];
        for(int i=0;i<n;i++)
        {
            if(manager[i]==-1)continue;
            list[manager[i]].push_back(i);
        }
        return helper(headID,list,informTime);
    }
};