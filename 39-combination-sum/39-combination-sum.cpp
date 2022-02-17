class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>List;
        vector<int>ans;
        sort(candidates.begin(),candidates.end());
        subset(0,target,candidates,List,ans);
            return List;
    }
    void subset(int idx,int target,vector<int>arr,vector<vector<int>>&list,vector<int>ans)
    {
        if(idx==arr.size())
        {
            if(target==0)list.push_back(ans);
            return;
        }
        if(target>=arr[idx])
        {
            ans.push_back(arr[idx]);
            subset(idx,target-arr[idx],arr,list,ans);
            ans.pop_back();
        }
        subset(idx+1,target,arr,list,ans);
    }
};