class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int tail=0,head=-1,n=nums.size();
        long long count=0;
        while(tail<n)
        {
            while(head+1<n&&nums[head+1]==0)
            {
                head++;
            }
            if(head!=-1&&nums[head]==0&&nums[tail]==0)
                count+=head-tail+1;
            if(tail>head)
            {
                head=tail;
            }
            else
            {
                tail++;
            }
        }
        return count;
    }
};