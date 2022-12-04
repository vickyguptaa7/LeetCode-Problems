class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long rightSum=accumulate(nums.begin(),nums.end(),0ll);
        int minAverage=1e9,n=nums.size(),indx=0;
        long long leftSum=0;
        for(int i=0;i<n;i++)
        {
            leftSum+=nums[i];
            rightSum-=nums[i];
            long long avg=leftSum/(i+1);
            if(i!=n-1)
            {
                avg=abs(avg-rightSum/(n-i-1));
            }
            if(minAverage>avg)
            {
                minAverage=avg;
                indx=i;
            }
        }
        return indx;
    }
};