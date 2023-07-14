class Solution {
    
    bool isValid(vector<int>&nums,int k,int maxSum)
    {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>maxSum)
            {
                sum=nums[i];
                k--;
            }
        }
        return k>0;
    }
    
public:
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end()),
        high=accumulate(nums.begin(),nums.end(),0);
        int result=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isValid(nums,k,mid))
            {
                result=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return result;
    }
};