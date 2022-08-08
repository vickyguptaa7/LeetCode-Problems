class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>arr;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            auto indx=lower_bound(arr.begin(),arr.end(),nums[i])-arr.begin();
            if(indx!=arr.size())
            {
                arr[indx]=nums[i];
            }
            else
            {
                arr.push_back(nums[i]);
            }
        }
        return arr.size();
    }
};