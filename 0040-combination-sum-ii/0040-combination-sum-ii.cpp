class Solution {
public:
    
    void helper(int strt,int sum,vector<int>&candidates,int target,vector<int>cand,
               vector<vector<int>>&result)
    {
        if(target==sum)
        {
            result.push_back(cand);
            return;
        }
        if(strt==candidates.size())
            return;
        for(int i=strt;i<candidates.size();i++)
        {
            if(sum+candidates[i]>target)
                break;
            if(i!=0&&candidates[i-1]==candidates[i]
               &&(cand.empty()||cand.back()+1!=i))
                continue;
            
            cand.push_back(i);
            helper(i+1,sum+candidates[i],candidates,target,cand,result);
            cand.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>cand;
        vector<vector<int>>result;
        helper(0,0,candidates,target,cand,result);
        for(auto &x:result)
        {
            for(auto &y:x )
            {
                y=candidates[y];
            }
        }
        return result;
    }
};