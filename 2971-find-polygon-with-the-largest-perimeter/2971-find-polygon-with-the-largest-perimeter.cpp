class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum=accumulate(nums.begin(),nums.end(),0ll);
        int count=0,n=nums.size();
        
        for(int i=n-1;i>=2;i--)
        {
            sum-=nums[i];
            if(sum<=nums[i])    
            {
                continue;
            }
            else
            {
                return sum+nums[i];
            }
        }
        
        return -1;
    }
};