class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int tail1=0,tail2=0;
        while(tail1<nums1.size()&&tail2<nums2.size())
        {
            if(nums1[tail1]==nums2[tail2])
                return nums1[tail1];
            else if(nums1[tail1]<nums2[tail2])
                tail1++;
            else 
                tail2++;
        }
        return -1;
    }
};