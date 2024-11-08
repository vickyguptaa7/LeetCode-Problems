class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xr=0,n=nums.size();
        for(auto &x:nums)
            xr=(xr^x);
        vector<int>res(n,0);
        for(int i=n-1;i>=0;i--)
        {
            int temp=xr,dummy=0;
            for(int i=0;i<maximumBit;i++)
            {
                if(!(temp&(1<<i)))
                {
                    dummy|=(1<<i);
                }
            }
            res[n-i-1]=dummy;
            xr=(xr^nums[i]);
        }
        return res;
    }
};