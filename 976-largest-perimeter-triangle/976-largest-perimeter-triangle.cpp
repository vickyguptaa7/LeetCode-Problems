class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int s1,s2,s3;
        for(int i=n-1;i>=2;i--)
        {
            s1=i;
            s2=i-1;
            s3=i-2;
            if(nums[s1]<nums[s2]+nums[s3])
            {
                return nums[s1]+nums[s2]+nums[s3];
            }
        }
        return 0;
    }
};