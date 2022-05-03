class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int it1=-1,it2=-1;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>nums[i])
            {
                it1=i-1;
                break;
            }
        }
        if(it1==-1)return 0;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i+1]<nums[i])
            {
                it2=i+1;
                break;
            }
        }
        int Min=nums[it1],Max=nums[it2];
        for(int i=it1;i<=it2;i++)
        {
            Min=min(Min,nums[i]);
            Max=max(Max,nums[i]);
        }
        while(it1>=0&&nums[it1]>Min)
        {
            it1--;
        }
        while(it2<n&&nums[it2]<Max)
        {
            it2++;
        }
        cout<<it1<<" "<<it2<<"\n";
        return it2-it1-1;
    }
};