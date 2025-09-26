class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int val=upper_bound(nums.begin(),nums.end(),nums[i]+nums[j]-1)-(nums.begin())-(j+1);
                count+=max(0,val);
            }
        }
        return count;
    }
};