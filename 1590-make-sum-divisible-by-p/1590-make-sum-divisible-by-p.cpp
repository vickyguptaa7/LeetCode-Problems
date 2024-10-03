class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum=accumulate(nums.begin(),nums.end(),0ll);
        if(sum%p==0)
            return 0;
        
        map<int,int>freq;
        int psum=0,rem=sum%p;
        freq[0]=-1;
        int res=1e9;
        for(int i=0;i<nums.size();i++)
        {
            psum+=nums[i];
            psum%=p;
            if(freq.count((psum+(p-rem))%p))
            {
                res=min(res,i-freq[(psum+(p-rem))%p]);
            }
            freq[psum]=i;
        }
        return res>=nums.size()?-1:res;
    }
};