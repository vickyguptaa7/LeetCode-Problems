class Solution {
    public int largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        int perimeter = 0;
        for(int i=2;i<nums.length;i++)
        {
            int a = nums[i], b = nums[i-1], c = nums[i-2];
            if((a+b)>c && (a+c)>b && (b+c)>a)
            {
                perimeter = Math.max(perimeter, a+b+c);
            }
        }
        return perimeter;
    }
}