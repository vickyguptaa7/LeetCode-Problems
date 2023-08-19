class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int pairs=0;
        sort(nums.begin(),nums.end());
        int right=(int)nums.size()-1,left=0;
        while(left<right)
        {
            int sum=nums[left]+nums[right];
            if(sum>=target)
            {
                right--;
            }
            else
            {
                pairs+=right-left;
                left++;
            }
        }
        return pairs;
    }
};