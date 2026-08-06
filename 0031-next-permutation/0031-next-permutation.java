class Solution {
    public void nextPermutation(int[] nums) {
        int n = nums.length;
        int replaceIndex = 0, maxIndex=n-1;
        for(int i = n-2; i>=0; i--)
        {
            if(nums[i]<nums[i+1])
            {
                replaceIndex = i+1;
                int tar=i+1;
                for(int j=i+1;j<n;j++)
                {
                    if(nums[j]-nums[i]<=0)continue;

                    tar = ((nums[tar]-nums[i])<(nums[j]-nums[i]))?tar:j;
                }
                int temp = nums[i];
                nums[i] = nums[tar];
                nums[tar] = temp;
                break;
            }
        }
        for(int i=replaceIndex;i<(n+replaceIndex)/2;i++)
        {
            int temp = nums[i];
            int swapIndex = n - 1 - (i - replaceIndex);
            nums[i] = nums[swapIndex];
            nums[swapIndex] = temp;
        }
    }
}

// 1 2 3 -> 1 3 2 -> 2 1 3 -> 2 3 1 -> 3 1 2 -> 3 2 1 
// 1 2 3 4 -> 1 2 4 3 -> 1 3 2 4