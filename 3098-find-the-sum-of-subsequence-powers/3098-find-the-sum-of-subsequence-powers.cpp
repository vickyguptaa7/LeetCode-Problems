class Solution {
    int dp[52][52][52][51];
    int mod=1e9+7;
public:
    
    int helper(int curr,int last,int indx1,int indx2,int k,vector<int>&nums)
    {
        if(k==0)return abs(nums[indx2]-nums[indx1]);
        if(curr==nums.size())return 0;
        if(dp[last+1][indx1+1][indx2+1][k]!=-1)
        {
            return dp[last+1][indx1+1][indx2+1][k];
        }
        
        int temp1=indx1,temp2=indx2;
        if(last!=-1&&(indx1==-1||indx2==-1||abs(nums[indx2]-nums[indx1])>abs(nums[curr]-nums[last])))
        {
            temp1=last;
            temp2=curr;
        }
        
        int inc=helper(curr+1,curr,temp1,temp2,k-1,nums);
        int exc=helper(curr+1,last,indx1,indx2,k,nums);
        
        return dp[last+1][indx1+1][indx2+1][k]=(inc+exc)%mod;
    }
    
    int sumOfPowers(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        sort(nums.begin(),nums.end());
        return helper(0,-1,-1,-1,k,nums);
    }
};