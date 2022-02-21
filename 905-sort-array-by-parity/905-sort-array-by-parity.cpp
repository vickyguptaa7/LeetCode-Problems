class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int iter1=-1,iter2=0;

        int numLen=nums.size();
        while(iter2<numLen)
        {
            if(nums[iter2]&1)
            {
                iter2++;
            }
            else
            {
                iter1++;
                swap(nums[iter1],nums[iter2]);
                iter2++;
            }
        }
        return nums;
    }
};