class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int size=nums.size();
        int it1=0,it2=size-1,result=0;
        while(it1<it2)
        {
            int sum=nums[it1]+nums[it2];
            if(sum==k)
            {
                it1++;
                it2--;
                result++;
            }
            else if(sum>k)
            {
                it2--;
            }
            else
            {
                it1++;
            }
        }
        return result;
    }
};