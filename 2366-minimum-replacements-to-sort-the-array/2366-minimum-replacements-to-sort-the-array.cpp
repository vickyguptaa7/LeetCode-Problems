class Solution {
public:

    long long minimumReplacement(vector<int>& nums) {
        int size=nums.size();
        long long mnoper=0,prev=nums.back();
        for(int i=size-2;i>=0;i--)
        {
            mnoper+=ceil(nums[i]/(prev*1.0))-1ll;
            prev=nums[i]/(ceil(nums[i]/(prev*1.0)));
        }
        return mnoper;
    }
};