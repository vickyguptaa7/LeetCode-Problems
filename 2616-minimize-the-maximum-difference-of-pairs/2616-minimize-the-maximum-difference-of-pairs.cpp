class Solution {
public:
    
    bool isValid(vector<int>&nums,int p,int mid)
    {
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]<=mid)
            {
                p--;
                i++;
            }
            if(p==0)
                return true;
        }
        return false;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        if(!p)
            return p;
        int low=0,high=*max_element(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        int ans=1e9;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isValid(nums,p,mid))
            {
                high=mid-1;
                ans=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};