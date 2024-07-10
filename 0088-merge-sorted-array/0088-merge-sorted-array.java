class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        
        int iterNums1=m-1,iterNums2=n-1,combinedIter=n+m-1;
        
        while(combinedIter>=0)
        {
            if(iterNums1>=0&&(iterNums2<0||nums1[iterNums1]>nums2[iterNums2]))
            {
                nums1[combinedIter--]=nums1[iterNums1--];
            }
            else
            {
                nums1[combinedIter--]=nums2[iterNums2--];
            }
        }
    }
}