class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int len=0,prev=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                k--;
            }
            if(k<0)
            {
                while(k<0&&prev<n)
                {
                    if(nums[prev++]==0)k++;
                }
            }
            len=max(len,i-prev+1);
        }
        return len;
    }
};