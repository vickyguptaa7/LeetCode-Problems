class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum=accumulate(nums.begin(),nums.end(),0ll);
        if(sum%p==0)
            return 0;
        map<int,vector<int>>mmindx;
        int n=nums.size();
        int minSize=n;
        for(int i=0;i<n;i++)
        {
            sum-=nums[i];
            if(sum%p==0)
            {
                minSize=min(minSize,i+1);
            }
            mmindx[sum%p].push_back(i+1);
        }
        sum=0;
        mmindx[p].push_back(n);
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            sum%=p;
            if(mmindx.count((p-sum)))
            {
                int indx=upper_bound(mmindx[p-sum].begin(),mmindx[p-sum].end()
                                                  ,i)-mmindx[p-sum].begin();
                if(indx==mmindx[p-sum].size())
                {
                    continue;
                }
                indx=mmindx[p-sum][indx];
                minSize=min(minSize,indx-i-1);
            }
        }
        return minSize==n?-1:minSize;
    }
};