class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        vector<int>newNums;
        for(int i=0;i<nums.size();i++)
        {
            int temp=nums[i],revNum=0;
            while(temp)
            {
                revNum=revNum*10+temp%10;
                temp/=10;
            }
            newNums.push_back(nums[i]-revNum);
        }
        int pairCount=0,mod=1e9+7;
        unordered_map<int,int>mmp;
        for(auto x:newNums)
        {
            if(mmp.count(x))
            {
                pairCount=(pairCount+mmp[x])%mod;
            }
            mmp[x]++;
        }
        return pairCount;
    }
};