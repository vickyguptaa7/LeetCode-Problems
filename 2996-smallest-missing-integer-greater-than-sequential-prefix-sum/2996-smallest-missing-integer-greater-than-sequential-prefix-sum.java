class Solution {
    public int missingInteger(int[] nums) {
        int cnt=1,sum=nums[0];
        for(int i=1;i<nums.length;i++)
        {
            if(nums[i]==nums[i-1]+1)
            {
                cnt++;
                sum+=nums[i];
            }
            else
            {
                break;
            }
        }
        for(int i=sum;i<2000;i++)
        {
            boolean is_present=false;
            for(int j=0;j<nums.length;j++)
            {
                if(i==nums[j])
                {
                    is_present=true;
                }
            }
            if(!is_present)
                return i;
        }
        return -1;
    }
}