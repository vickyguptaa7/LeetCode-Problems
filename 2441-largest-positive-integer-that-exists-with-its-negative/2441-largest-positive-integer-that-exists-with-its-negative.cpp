class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<int>freq(2005,0);
        int ans=-1;
        for(auto &x:nums)
        {
            if(x>0&&freq[-x+1000])
            {
                ans=max(ans,x);
            }
            else if(x<0&&freq[-x+1000])
            {
                ans=max(ans,-x);
            }
            freq[x+1000]++;
        }
        return ans;
    }
};