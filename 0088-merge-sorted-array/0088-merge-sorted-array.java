class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        
        int iterNums1=0,iterNums2=0,combinedIter=0;
        int[] combinedNums=new int[n+m];
        
        while(iterNums1<m&&iterNums2<n)
        {
            if(nums1[iterNums1]<nums2[iterNums2])
            {
                combinedNums[combinedIter++]=nums1[iterNums1++];
            }
            else
            {
                combinedNums[combinedIter++]=nums2[iterNums2++];
            }
        }
        
        while(iterNums1<m)
        {
            combinedNums[combinedIter++]=nums1[iterNums1++];
        }
        
        while(iterNums2<n)
        {
            combinedNums[combinedIter++]=nums2[iterNums2++];
        }
        
        combinedIter=0;
        for(int i=0;i<m+n;i++)
        {
            nums1[i]=combinedNums[combinedIter++];
        }
    }
}