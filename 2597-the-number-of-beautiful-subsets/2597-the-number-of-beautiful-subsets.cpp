class Solution {
public:
    
    void helper(int indx,vector<int>&nums,int k,vector<int>&freq,int &res)
    {
        if(indx==nums.size())
        {
            res++;
            return;
        }
        helper(indx+1,nums,k,freq,res);
        if(!freq[nums[indx]-k+1000]&&!freq[nums[indx]+k+1000])
        {
            freq[nums[indx]+1000]++;
            helper(indx+1,nums,k,freq,res);
            freq[nums[indx]+1000]--;
        }
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int>freq(3e3+5,0);
        int res=0;
        helper(0,nums,k,freq,res);
        return res-1;
    }
};