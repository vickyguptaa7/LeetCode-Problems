class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left=-1,curr=0,right=(int)nums.size()-1;
        while(curr<=right)
        {
            if(nums[curr]==1)
            {
                curr++;
            }
            else if(nums[curr]==0)
            {
                left++;
                swap(nums[curr],nums[left]);
                curr++;
            }
            else
            {
                swap(nums[curr],nums[right]);
                right--;
            }
        }
    }
};