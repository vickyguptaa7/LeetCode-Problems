class Solution {
public:
    bool BinarySearch(vector<int>&nums,int low,int high,int target)
    {
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)return true;
            else if(nums[mid]>target)high=mid-1;
            else low=mid+1;
        }
        return false;
    }
    int pivot(vector<int>&nums)
    {
        int low=0,high=nums.size()-1;
        int piv=0;
        while(low<high)
        {
            while(low<high&&nums[low+1]==nums[low])
            {
                low++;
            }
            while(low<high&&nums[high-1]==nums[high])
            {
                high--;
            }
            int mid=low+(high-low)/2;
   
            
            if(nums[mid]<=nums[high])
            {
                high=mid;
            }
            else 
            {
                low=mid+1;
            }
        }
        cout<<low<<" "<<high<<"\n";
        return low;
    }
    bool search(vector<int>& nums, int target) {
        int pivotIndex=pivot(nums);
        return (BinarySearch(nums,0,pivotIndex-1,target)||BinarySearch(nums,pivotIndex,nums.size()-1,target));
    }
};