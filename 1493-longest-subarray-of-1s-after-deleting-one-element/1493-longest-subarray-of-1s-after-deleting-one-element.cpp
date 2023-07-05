class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int longest=0,prev=0,zeroCount=0;
        for(int i=0;i<nums.size();i++)
        {
            zeroCount+=nums[i]==0;
            while(zeroCount>1)
            {
                zeroCount-=nums[prev]==0;
                prev++;
            }
            longest=max(longest,i-prev);
        }
        return longest;
    }
};