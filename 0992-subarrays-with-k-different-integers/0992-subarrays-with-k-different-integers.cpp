class Solution {
public:
    int helper(vector<int>& nums, int k)
    {
        int tail=0,head=-1;
        map<int,int>diff;
        int res=0,n=nums.size();
        while(head<n)
        {
            while(head+1<n&&diff.size()<k)
            {
                head++;
                diff[nums[head]]++;
            }
            
            if(diff.size()>=k)
                res+=(n-head);
            
            if(tail>head)
            {
                tail++;
                head=tail-1;
            }
            else
            {
                diff[nums[tail]]--;
                if(diff[nums[tail]]==0)
                {
                    diff.erase(nums[tail]);
                }
                tail++;
            }
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k+1);
    }
};