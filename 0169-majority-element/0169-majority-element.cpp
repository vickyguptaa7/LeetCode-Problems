class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq=0;
        int curr=0;
        for(int i=0;i<nums.size();i++)
        {
            if(curr==nums[i])
            {
                freq++;
            }
            else if(freq==0)
            {
                freq=1;
                curr=nums[i];
            }
            else
            {
                freq--;
            }
        }
        return curr;
    }
};