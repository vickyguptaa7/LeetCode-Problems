class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int zero_cnt=0;
        for(int i=0;i<n;i++)
        {
            zero_cnt+=(nums[i]==0)?1:0;
        }
        if(zero_cnt>1)
        {
            int[] res=new int[n];
            for(int i=0;i<n;i++)res[i]=0;
            return res;
        }
        int prod=1;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]==0)break;
            prod*=nums[i];
        }
        if(zero_cnt==1)
        {
            int[] res=new int[n];
            int p1=1;
            for(int i=0;i<n;i++)
            {
                if(nums[i]==0)
                {
                    res[i]=p1*prod;
                }
                else
                {
                    res[i]=0;
                }
                p1*=nums[i];
            }
            return res;
        }
        else
        {
            int[] res=new int[n];
            int p1=1;
            for(int i=0;i<n;i++)
            {
                prod/=nums[i];
                res[i]=p1*prod;
                p1*=nums[i];
            }
            return res;
        }
    }
}