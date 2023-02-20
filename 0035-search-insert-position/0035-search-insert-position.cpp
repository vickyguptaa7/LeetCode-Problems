class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0,high=(int)nums.size()-1,pos=nums.size();
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>=target)
            {
                pos= mid;
                high=mid-1;
            }
            else 
            {
                low=mid+1;
            }
        }
        return pos;
    }
};