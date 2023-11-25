class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        int rsum=0,lsum=0;
        for(int i=0;i<nums.size();i++)rsum+=nums[i];
        for(int i=0;i<nums.size();i++)
        {
            lsum+=nums[i];
            int left=nums[i]*(i+1)-lsum;
            int right=rsum-nums[i]*(n-i);
            res.push_back(left+right);
            rsum-=nums[i];
        }
        return res;
    }
};