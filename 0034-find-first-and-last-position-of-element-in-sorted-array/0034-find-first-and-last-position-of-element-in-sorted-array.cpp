class Solution {
public:
    
    int lastPosition(vector<int>&nums,int target)
    {
        int low=0,high=nums.size()-1,ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]<=target)
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        if(ans==-1)
            return ans;
        return nums[ans]!=target?-1:ans;
    }
    
    int firstPosition(vector<int>&nums,int target)
    {
        int low=0,high=nums.size()-1,ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>=target)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        if(ans==-1)
            return ans;
        return nums[ans]!=target?-1:ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=firstPosition(nums,target);
        int last=lastPosition(nums,target);
        if(first==-1)
            return {-1,-1};
        return {first,last};
    }
};