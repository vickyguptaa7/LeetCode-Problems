class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=accumulate(nums1.begin(),nums1.end(),0ll);
        long long sum2=accumulate(nums2.begin(),nums2.end(),0ll);
        
        long long zcount1=0,zcount2=0;
        for(int i=0;i<nums1.size();i++)zcount1+=nums1[i]==0;
        for(int i=0;i<nums2.size();i++)zcount2+=nums2[i]==0;
        
        if(sum1+zcount1>sum2+zcount2)
        {
            if(zcount2==0)
                return -1;
        }
        else if(sum1+zcount1<sum2+zcount2)
        {
            if(zcount1==0)
                return -1;
        }
        return max(sum1+zcount1,sum2+zcount2);
    }
};