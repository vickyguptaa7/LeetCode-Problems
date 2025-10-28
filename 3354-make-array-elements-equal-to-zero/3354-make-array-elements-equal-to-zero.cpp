class Solution {
public:
    bool isValid(int startPos,int dir,vector<int>nums)
    {
        int curr=startPos;
        while(curr>=0&&curr<nums.size())
        {
            if(nums[curr]!=0) {
                nums[curr]--;
                dir=(dir==1)?-1:1;
            }
            curr+=dir;
        }
        return accumulate(nums.begin(),nums.end(),0)==0;
    }

    int countValidSelections(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==0)
                count+=isValid(i,1,nums)+isValid(i,-1,nums);
        }
        return count;
    }
};