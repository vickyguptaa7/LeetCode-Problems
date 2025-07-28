class Solution {

    public int countMaxOrSubsets(int[] nums) {
        int maxOr=0,size=nums.length;
        for(int i=0;i<size;i++)
            maxOr|=nums[i];
        
        int subset=0,possible=(1<<size);
        for(int i=0;i<possible;i++)
        {
            int orr=0;
            for(int j=0;j<size;j++)
            {
                if((i&(1<<j))>0)
                {
                    orr|=nums[j];
                }
            }
            subset+=(maxOr==orr?1:0);
        }
        return subset;
    }
}