class Solution {
    
    public int removeElement(int[] nums, int val) {
        int head=0,tail=-1,removed=0;
        while(head<nums.length)
        {
            if(nums[head]!=val)
            {
                tail++;
                if(head!=tail)
                {
                    nums[head]+=nums[tail];
                    nums[tail]=nums[head]-nums[tail];
                    nums[head]-=nums[tail];
                }
            }
            else
            {
                removed++;
            }
            head++;
        }
        return nums.length-removed;
    }
}