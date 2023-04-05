class Solution {
public:
    
    bool isValid(int k,vector<int>&nums)
    {
        int n=nums.size();
        long long carry=0;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]+carry>k)
            {
                carry=(nums[i]+carry)-k;
            }
            else
            {
                carry=0;
            }
        }
        return carry==0;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        int low=0,high=1e9,ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(isValid(mid,nums))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};