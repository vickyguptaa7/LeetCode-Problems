class Solution
{
    public:

        void helper(int indx, vector<int> &nums,long long ans,long long &result)
        {
            result=max(result,ans);
            if (indx == nums.size())
                return;
            helper(indx+1,nums,ans,result);
            if(ans==-1e18)
            {
                ans=1;
            }
            helper(indx+1,nums,ans*nums[indx],result);
        }

    long long maxStrength(vector<int> &nums)
    {
        long long res=-1e18;
        helper(0,nums,-1e18,res);
        return res;
    }
};