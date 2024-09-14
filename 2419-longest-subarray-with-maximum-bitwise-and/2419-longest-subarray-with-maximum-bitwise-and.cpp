class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        int counter=0,ans=1;
        for(int i=0;i<nums.size();i++)
        {
            if((mx&nums[i])==mx)
            {
                counter++;
            }
            else
            {
                counter=0;
            }
            ans=max(ans,counter);
        }
        return ans;
    }
};