class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        int minOperation=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                continue;
            }
            else
            {
                int oper=nums[i-1]-nums[i]+1;
                minOperation+=oper;
                nums[i]+=oper;
            }
        }
        return minOperation;
    }
};