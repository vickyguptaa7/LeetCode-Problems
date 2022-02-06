class Solution {
public:

    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int rep=0,freq=1,itr=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[rep])
            {
                freq++;
                if(freq>2)
                continue;
            }
            else 
            {
                rep=i;
                freq=1;
            }
            nums[itr++]=nums[i];
        }
        return itr;
    }
};