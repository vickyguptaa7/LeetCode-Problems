class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int overallMax=-1e9;
        int mx=1,mn=1;
        for(int i=0;i<nums.size();i++)
        {
            int temp=mx;
            mx=max({mx*nums[i],mn*nums[i]});
            mn=min({mn*nums[i],temp*nums[i]});
            overallMax=max(overallMax,mx);
            
            if(mx<=0)
                mx=1;
            if(mn>=0)
                mn=1;
        }
        return overallMax;
    }
};