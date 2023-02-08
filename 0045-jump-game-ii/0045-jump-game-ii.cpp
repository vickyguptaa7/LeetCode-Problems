class Solution {
public:
    
    int helper(int indx,int n,vector<int>&nums,vector<int>&dp)
    {
        if(indx>=n-1)
        {
            return 0;
        }
        if(dp[indx]!=-1)
            return dp[indx];
        int minJmp=1e9;
        for(int i=indx+1;i<=indx+nums[indx];i++)
        {
            minJmp=min(minJmp,1+helper(i,n,nums,dp));
        }
        return dp[indx]=minJmp;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        int n=nums.size();
        cout<<n<<"\n";
        return helper(0,n,nums,dp);
    }
};