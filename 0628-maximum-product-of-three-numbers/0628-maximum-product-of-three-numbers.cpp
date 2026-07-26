class Solution {
public:
    // posibilities : 
    // {mn1,mn2,mx1}, {mx1,mx2,mx3}
    int maximumProduct(vector<int>& nums) {
        int mx1=-1e9,mx2=-1e9,mx3=-1e9;
        int mn1=1e9,mn2=1e9;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>mx1)
            {
                mx3=mx2;
                mx2=mx1;
                mx1=nums[i];
            }
            else if(nums[i]>mx2)
            {
                mx3=mx2;
                mx2=nums[i];
            }
            else
            {
                mx3=max(mx3,nums[i]);
            }

            if(nums[i]<mn1)
            {
                mn2=mn1;
                mn1=nums[i];
            }
            else
            {
                mn2=min(mn2,nums[i]);
            }
        }
        return max({mn1*mn2*mx1,mx1*mx2*mx3});
    }
};