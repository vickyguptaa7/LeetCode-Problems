class Solution {
public:
    
    bool helper(int strt,int sum,vector<int>&nums,int k,int target,vector<int>&visited)
    {
        if(k==1)
            return true;
        
        if(strt>=nums.size())
            return false;
        
        if(target==sum)
            return helper(0,0,nums,k-1,target,visited);
        
        for(int i=strt;i<nums.size();i++)
        {
            if(visited[i]||sum+nums[i]>target)
                continue;
            visited[i]=true;
            if(helper(i+1,sum+nums[i],nums,k,target,visited))
                return true;
            visited[i]=false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k)
            return false;
        vector<int>visited(nums.size(),false);
        return helper(0,0,nums,k,sum/k,visited);
    }
};