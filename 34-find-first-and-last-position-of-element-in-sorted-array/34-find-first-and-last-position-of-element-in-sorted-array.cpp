class Solution {
public:
    int firstOccr(vector<int>&nums,int target)
    {
        int low=0,high=nums.size();
        high--;
        int indx=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(target>nums[mid])
            {
                low=mid+1;
            }
            else
            {
                indx=mid;
                high=mid-1;
            }
        }
        if(indx!=-1&&nums[indx]!=target)indx=-1;
        return indx;
    }
    int secondOccr(vector<int>&nums,int target)
    {
        int low=0,high=nums.size();
        high--;
        int indx=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(target>=nums[mid])
            {
                indx=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        if(indx!=-1&&nums[indx]!=target)indx=-1;
        return indx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstOccr(nums,target),secondOccr(nums,target)};
    }
};