class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr=nums[0],next=0;
        for(int i=1;i<nums.size();i++)
        {
            if(i<=curr)
            {
                next=max(next,i+nums[i]);
            }
            else
            {
                curr=next;
                next=nums[i]+i;
                if(curr<i)
                    return false;
            }
        }
        return true;
    }
};