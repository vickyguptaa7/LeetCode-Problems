class Solution {
public:
    void sortColors(vector<int>& nums) {
        int first=-1,last=nums.size()-1;
        for(int i=0;i<nums.size();i++)
        {
            if(i>last)break;
            if(nums[i]==1)continue;
            if(nums[i]==0)
            {
                first++;
                swap(nums[first],nums[i]);
            }
            else
            {
                swap(nums[last],nums[i]);
                last--;
                i--;
            }
        }
    }
};