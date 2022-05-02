class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int size=nums.size();
        int it1=-1,it2=0;
        while(it2<size)
        {
            if(nums[it2]&1)
            {
                it2++;
            }
            else
            {
                it1++;
                swap(nums[it1],nums[it2]);
                it2++;
            }
        }
        return nums;
    }
};