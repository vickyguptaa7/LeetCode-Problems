class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int startIndx=nums.size(),lastIndx=-1,size=nums.size();
        for(int i=0;i<size-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                startIndx=i;
                break;
            }
        }
        for(int i=size-2;i>=0;i--)
        {
            if(nums[i]>nums[i+1])
            {
                lastIndx=i+1;
                break;
            }
        }
        if(lastIndx<startIndx)
        {
            return 0;
        }
        int minEle=1e9,maxEle=-1e9;
        for(int i=startIndx;i<=lastIndx;i++)
        {
            minEle=min(minEle,nums[i]);
            maxEle=max(maxEle,nums[i]);
        }
        for(int i=0;i<size;i++)
        {
            if(nums[i]>minEle)
            {
                startIndx=i;
                break;
            }
        }
        for(int i=size-1;i>=0;i--)
        {
            if(nums[i]<maxEle)
            {
                lastIndx=i;
                break;
            }
        }
        return lastIndx-startIndx+1;
    }
};