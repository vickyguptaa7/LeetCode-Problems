class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        for(int i=0;i<nums1.size();i++)
        {
            if(nums2.size()&1)
            {
                ans^=nums1[i];
            }
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(nums1.size()&1)
            {
                ans^=nums2[i];
            }
        }
        return ans;
    }
};