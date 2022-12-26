class Solution {
public:
    bool canJump(vector<int>& nums) {
        int nextJump=0,currJump=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            nextJump=max(nextJump,i+nums[i]);
            if(currJump-i==0)
            {
                currJump=nextJump;
                nextJump=0;
            }
            else if(currJump-i<0)
            {
                return false;
            }
        }
        return true;
    }
};