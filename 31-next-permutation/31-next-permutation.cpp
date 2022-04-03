class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int iter=n-1;
        while(iter>0)
        {
            if(nums[iter]>nums[iter-1])break;
            iter--;
        }
        if(iter==0)
        {
            sort(nums.begin(),nums.end());
            return;
        }
        iter--;
        int iter2=n-1;
        for(iter2;iter2>iter;iter2--)
        {
            if(nums[iter]<nums[iter2])break;
        }
        swap(nums[iter],nums[iter2]);
        reverse(nums.begin()+iter+1,nums.end());
    }
};