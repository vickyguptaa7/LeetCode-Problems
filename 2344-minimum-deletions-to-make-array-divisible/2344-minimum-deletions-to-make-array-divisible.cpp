class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(),nums.end());
        int gcd=numsDivide[0];
        for(auto x:numsDivide)
        {
            gcd=__gcd(gcd,x);
        }
        int del=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==gcd||gcd%nums[i]==0)
            {
                break;
            }
            del++;
        }
        return del==nums.size()?-1:del;
    }
};