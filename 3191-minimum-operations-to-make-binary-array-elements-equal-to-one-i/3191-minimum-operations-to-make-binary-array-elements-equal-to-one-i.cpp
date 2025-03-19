class Solution {
public:
    int minOperations(vector<int>& nums) {
        int oper=0,n=nums.size();
        for(int i=0;i<n-2;i++)
        {
            if(nums[i]==1)
                continue;
            oper++;
            nums[i]^=1;
            nums[i+1]^=1;
            nums[i+2]^=1;
        }
        return nums[n-2]&&nums[n-1]?oper:-1;
    }
};