class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int>res,presum(nums.size()+1,0);
        for(int i=1;i<=nums.size();i++)presum[i]=presum[i-1]+nums[i-1];
        for(int i=0;i<nums.size();i++)
        {
            int left=nums[i]*(i+1)-(presum[i+1]-presum[0]);
            int right=(presum[n]-presum[i])-nums[i]*(n-i);
            res.push_back(left+right);
        }
        return res;
    }
};