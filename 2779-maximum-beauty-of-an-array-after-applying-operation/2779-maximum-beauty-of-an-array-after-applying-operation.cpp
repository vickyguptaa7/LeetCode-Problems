class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int>range(2e5+5,0);
        for(int i=0;i<nums.size();i++)
        {
            int l=max(0,nums[i]-k);
            int r=nums[i]+k;
            range[l]++;
            range[r+1]--;
        }
        int ans=0;
        for(int i=0;i<range.size();i++)
        {
            range[i]+=(i!=0?range[i-1]:0);
            ans=max(ans,range[i]);
        }
        return ans;
    }
};