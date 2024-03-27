class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prod=1,res=0;
        int tail=0,head=-1,n=nums.size();
        while(tail<n)
        {
            while(head+1<n&&prod*nums[head+1]<k)
            {
                head++;
                prod*=nums[head];
            }
            res+=(head-tail+1);
            
            if(head<tail)
            {
                tail++;
                head=tail-1;
            }
            else
            {
                prod/=nums[tail];
                tail++;
            }
        }
        return res;
    }
};