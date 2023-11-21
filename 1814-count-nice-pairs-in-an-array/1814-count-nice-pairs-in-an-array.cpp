class Solution {
public:
    
    long long reverseNum(int num)
    {
        long long rev=0;
        while(num)
        {
            rev=rev*10+num%10;
            num/=10;
        }
        return rev;
    }
    
    int countNicePairs(vector<int>& nums) {
        unordered_map<long long,int>mp;
        int count=0,mod=1e9+7;
        for(int i=0;i<nums.size();i++)
        {
            long long val=nums[i]-reverseNum(nums[i]);
            count=(count+mp[val])%mod;
            mp[val]++;
        }
        return count;
    }
};