class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans=0;
           for(int i=0;i<nums.size();i++)
           {
                int target_count=0;
                for(int j=i;j<nums.size();j++)
                {
                    int len = j-i+1;
                    target_count+=nums[j]==target;
                    ans+=(target_count*2>len);

                }
           }
           return ans;
    }
};